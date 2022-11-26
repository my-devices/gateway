# The macchina.io REMOTE Gateway

## About macchina.io REMOTE

[macchina.io REMOTE](https://macchina.io/remote) provides secure remote access to connected devices
via HTTP or other TCP-based protocols and applications such as secure shell (SSH) or
Virtual Network Computing (VNC). With macchina.io REMOTE, any network-connected device
running the macchina.io REMOTE Device Agent or this Gateway program can be securely accessed remotely over the
internet from browsers, mobile apps, desktop, server or cloud applications.

This even works if the device is behind a NAT router, firewall or proxy server.
The device becomes just another host on the internet, addressable via its own URL and
protected by the macchina.io REMOTE server against unauthorized or malicious access.
macchina.io REMOTE is a great solution for secure remote support and maintenance,
as well as for providing secure remote access to devices for end-users via web or
mobile apps.

Visit [macchina.io/remote](https://macchina.io/remote) to learn more and to register for a free account.
Specifically, see the [Getting Started](https://macchina.io/remote.html#signup) page and the
[Frequently Asked Questions](https://macchina.io/remote_faq.html) for
information on how to use this SDK and the included *WebTunnelAgent* executable.

There is also a [blog post](https://macchina.io/blog/?p=257) showing step-by-step instructions to connect a Raspberry Pi.


## About the macchina.io REMOTE Gateway

The macchina.io REMOTE Gateway is similar to the macchina.io REMOTE Agent from the SDK, but allows you to
connect multiple devices or services to the macchina.io REMOTE server using
a single Gateway server instance. The Gateway also has a built-in web user interface
for managing device/service connections.

The macchina.io REMOTE Gateway requires the [macchina.io REMOTE SDK](https://github.com/my-devices/sdk).

Like the SDK, the Gateway is licensed under the [Boost Software License](https://spdx.org/licenses/BSL-1.0).


## Building the Gateway

The Gateway can be built on Linux, macOS and Windows with CMake.


### 1. Clone the SDK and Gatway repositories.

Note: If you've already cloned the SDK repository, you do not need to clone it again. Just make sure
that the `gateway` repository is in the same directory, alongside the `sdk` repository.

```
$ mkdir my-devices && cd my-devices
$ git clone https://github.com/my-devices/sdk.git
$ git clone https://github.com/my-devices/gateway.git
```

### 2. Build and Install the SDK.

The SDK should be build and installed to a directory so that it can later
be picked up by CMake when building the Gateway.

```
$ mkdir sdk-build && cd sdk-build
$ cmake ../sdk \
	-DENABLE_JSON=ON \
	-DENABLE_PAGECOMPILER=ON \
	-DENABLE_PAGECOMPILER_FILE2PAGE=ON \
	-DENABLE_WEBTUNNELAGENT=OFF \
	-DENABLE_WEBTUNNELCLIENT=OFF \
	-DENABLE_WEBTUNNELSSH=OFF \
	-DENABLE_WEBTUNNELVNC=OFF \
	-DENABLE_WEBTUNNELRDP=OFF \
	-DCMAKE_INSTALL_PREFIX=../sdk-install
$ cmake --build . --config Release --target install
$ cd ..
```

See the [SDK README](https://github.com/my-devices/sdk/blob/master/README.md) for
more options, specifically providing the path to OpenSSL headers and libraries
and cross-compilation.

To cross-compile, add `-DCMAKE_TOOLCHAIN_FILE=/path/to/toolchain.cmake` to the
`cmake` configuration command.

### 3. Build the Gateway

The important part is specifying the `CMAKE_PREFIX_PATH` so that the SDK
headers and libraries will be found.

```
$ mkdir gateway-build && cd gateway-build
$ cmake ../gateway -DCMAKE_PREFIX_PATH=../sdk-install
$ cmake --build . --config Release
```

To cross-compile, add `-DCMAKE_TOOLCHAIN_FILE=/path/to/toolchain.cmake` to the
`cmake` configuration command.

Note: The resulting `rmgateway` executable may contain debug information, which significantly
increases its size.
You should run `strip` or `xxx-yyy-linux-strip` on the resulting executable to reduce its
size before deploying it to the device.

## Running the Gateway

Review the configuration file [rmgateway.properties](rmgateway.properties) and
make some changes to the configuration if desired.

The most important setting is `webtunnel.domain`, which specifies the default
domain any devices created through the web user interface will be assigned to.
This can be left at the default (`00000000-0000-0000-0000-000000000000`).
In this case, the default domain of the logged-in user will be used. The default
domain UUID can be overridden when creating a device.

The value of the `webtunnel.domain` property can also be set to a specific value.
In this case, when a user logs in, the Gateway will verify that the user has access
to that specific domain, and deny login if not.

Optionally, you can also change other configuration properties, such as the
port of the internal web server (defaults to 8080).

You can change the address (URI) of the macchina.io REMOTE server
the agent connects to via the `webtunnel.reflectorURI` property.

Copy the `rmgateway.properties` file to the same directory
the `rmgateway` executable is located in, or use the `--config-file` option
to specify the path to the configuration file.

Finally, run `rmgateway`:

```
$ ./rmgateway
```

and open its configuration web interface at
[http://localhost:8080](http://localhost:8080).

You should see this:

![Gateway Web User Interface - First Login][login]

Sign in with your macchina.io REMOTE username and password.
The Gateway will validate the username and password
against the macchina.io REMOTE server instance configured
in the `webtunnel.reflectorURI` property.

After signing in you'll see the Local Devices overview page.

![Gateway Web User Interface - Overview][browser1]

Click the `[+]` button to create a new device connection. Your first device
can be to the built-in web interface of the Gateway, so that you will be able
to manage it remotely.

Enter the following information to make the Gateway's web user interface accessible remotely
via macchina.io REMOTE:

![Gateway Web User Interface - Create Device][create]

  - **Name:** `Gateway`
  - **ID:** *(leave as is)*
  - **Domain:** *(leave as is)*

Click *Next* to finish configuring the device.

![Gateway Web User Interface - Create Device][device]

Specify the following settings.

  - **Device IP Address or Domain Name:** `127.0.0.1`
  - **HTTP Server Port:** `8080` (or whatever port you have configured)
  - **Requires HTTPS:** unchecked

All other fields can be left at their defaults or empty.

Click `Save` to save your first Gateway connection.

You will now see the new device in the overview:

![Gateway Web User Interface - Device Added][browser2]

Note that *Status* may initially show *disconnected* for your newly added device.
The status should refresh after a few seconds and change to *connected*.
If the status shows *error*, click on the device to see the error message.

The Gateway should now also be visible in your [macchina.io REMOTE Dashboard](https://remote.macchina.io).

You can now manage the Gateway remotely via macchina.io REMOTE, and you can also add other
devices as well.


[login]: doc/images/login.png "Gateway Web User Interface - First Login"
[browser1]: doc/images/browser1.png "Gateway Web User Interface - Overview"
[create]: doc/images/create.png "Gateway Web User Interface - Create Device"
[device]: doc/images/device.png "Gateway Web User Interface - Create Device"
[browser2]: doc/images/browser2.png "Gateway Web User Interface - Device Created"
