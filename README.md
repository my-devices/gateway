# The macchina.io Remote Manager Gateway

## About macchina.io Remote Manager

[macchina.io Remote Manager](https://macchina.io/remote.html) provides secure remote access to connected devices
via HTTP or other TCP-based protocols and applications such as secure shell (SSH) or
Virtual Network Computing (VNC). With macchina.io Remote Manager, any network-connected device
running the Remote Manager Agent or this Gateway program can be securely accessed remotely over the
internet from browsers, mobile apps, desktop, server or cloud applications.

This even works if the device is behind a NAT router, firewall or proxy server.
The device becomes just another host on the internet, addressable via its own URL and
protected by the Remote Manager server against unauthorized or malicious access.
Remote Manager is a great solution for secure remote support and maintenance,
as well as for providing secure remote access to devices for end-users via web or
mobile apps.

Visit [macchina.io](https://macchina.io/remote.html) to learn more and to register for a free account.
Specifically, see the [Getting Started](https://macchina.io/remote.html#signup) page and the
[Frequently Asked Questions](https://macchina.io/remote_faq.html) for
information on how to use this SDK and the included *WebTunnelAgent* executable.

There is also a [blog post](https://macchina.io/blog/?p=257) showing step-by-step instructions to connect a Raspberry Pi.


## About the macchina.io Remote Manager Gateway

The macchina.io Remote Manager Gateway is similar to the Remote Manager Agent from the SDK, but allows you to
connect multiple devices or services to the Remote Manager server using
a single Gateway server instance. The Gateway also has a built-in web user interface
for managing device/service connections.

The Remote Manager Gateway requires the [Remote Manager SDK](https://github.com/my-devices/sdk).

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
$ cmake ../sdk -DCMAKE_INSTALL_PREFIX=../sdk-install
$ cmake --build . --target install
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
$ cmake --build .
```

To cross-compile, add `-DCMAKE_TOOLCHAIN_FILE=/path/to/toolchain.cmake` to the
`cmake` configuration command.

## Running the Gateway

Edit the configuration file [rmgateway.properties](rmgateway.properties) and change the default password
and Remote Manager domain.

To change the password, run:

```
$ ./rmgateway -H<password>
```

to compute the password hash. Change the value of the `gateway.password` property
to the hash value for your password.

Example: if your password is `sup3rS3cr3t`:

```
$ ./rmgateway -Hsup3rS3cr3t
61cba3bd7cc5bc6f3441a58c290e10a40f3cbcf6d1f538071d45a77e823273b0
```

Change the `gateway.password` property in `rmgateway.properties` to:

```
gateway.password = 61cba3bd7cc5bc6f3441a58c290e10a40f3cbcf6d1f538071d45a77e823273b0
```

Next, change the value of the `webtunnel.domain` property to the domain UUID of your
Remote Manager server account.

Optionally, you can also change other configuration properties, such as the
port of the internal web server (defaults to 8080).

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

![Gateway Web User Interface - First Start][browser1]

Click the `[+]` button to create a new device connection. Your first device
can be to the built-in web interface of the Gateway, so that you will be able
to manage it remotely.

Enter the following information to make the Gateway's web user interface accessible remotely
via Remote Manager:

  - **Name:** `Gateway`
  - **Domain:** *(leave as is)*
  - **Device Password:** *(leave empty)*
  - **Device IP Address or Domain Name:** `127.0.0.1`
  - **Forwarded TCP Ports:** `8080`
  - **Device HTTP Server Port:** `8080`

![Gateway Web User Interface - Add Device][browser2]

Click `Save` to save your first Gateway connection.

You will now see it in the overview:

![Gateway Web User Interface - Device Added][browser3]

Note that *Status* may initially show *disconnected* for your newly added device.
The page will refresh automatically after 10 seconds, and the status should
change to *connected*. If the status shows *error*, click on the device to
see the error message.

The Gateway should now be visible in your [Remote Manager Dashboard](https://reflector.my-devices.net).

You can now add other devices.


[browser1]: doc/images/browser1.png "Gateway Web User Interface - First Start"
[browser2]: doc/images/browser2.png "Gateway Web User Interface - Add Device"
[browser3]: doc/images/browser3.png "Gateway Web User Interface - Device Added"
