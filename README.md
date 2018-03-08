# The my-devices.net Gateway

## About my-devices.net

[my-devices.net](http://www.my-devices.net) provides secure remote access to connected devices
via HTTP or other TCP-based protocols and applications such as secure shell (SSH) or
Virtual Network Computing (VNC). With my-devices.net, any network-connected device
running the my-devices.net Agent or this Gateway program can be securely accessed remotely over the
internet from browsers, mobile apps, desktop, server or cloud applications.

This even works if the device is behind a NAT router, firewall or proxy server.
The device becomes just another host on the internet, addressable via its own URL and
protected by the my-devices.net server against unauthorized or malicious access.
my-devices.net is a great solution for secure remote support and maintenance,
as well as for providing secure remote access to devices for end-users via web or
mobile apps.

Visit [my-devices.net](http://www.my-devices.net) to learn more and to register for a free account.
Specifically, see the [Getting Started](http://www.my-devices.net/getstarted.html) page and the
[Frequently Asked Questions](http://www.my-devices.net/learnmore.html) for
information on how to use this SDK and the included *WebTunnelAgent* executable.

There is also a [blog post](http://www.appinf.com/blog/?p=257) showing step-by-step instructions to connect a Raspberry Pi.


## About the my-devices.net Gateway

The my-devices.net Gateway is similar to the Agent from the SDK, but allows you to
connect multiple devices or services to the my-device.net reflector server using
a single Gateway server instance. The Gateway also has a built-in web user interface
for managing device/service connections.

The my-devices.net Gateway requires the [my-devices.net SDK](https://github.com/my-devices/sdk).

Like the SDK, the Gateway is licensed under the [Boost Software License](https://spdx.org/licenses/BSL-1.0).


## Building the Gateway

The Gateway can be built on Linux and macOS. Project files for Visual Studio will be
provided later.

### 1. Clone the SDK and Gatway repositories.

Note: If you've already cloned the SDK repository, you do not need to clone it again. Just make sure
that the `gateway` repository is in the same directory, alongside the `sdk` repository.

```
$ mkdir my-devices
$ cd my-devices
$ git clone https://github.com/my-devices/sdk.git
$ git clone https://github.com/my-devices/gateway.git
```

### 2. Build the SDK.

```
$ (cd sdk && ./buildsdk.sh)
```

See the [SDK README](https://github.com/my-devices/sdk/blob/master/README.md) for
more options, specifically cross-compilation.

### 3. Build the Agent

```
$ make -s -C gateway shared_release
```

## Running the Gateway

Edit the configuration file [mygateway.properties](mygateway.properties) and change the default password
and my-devices.net domain.

To change the password, run:

```
$ gateway/bin/Linux/x86_64/mygateway -H<password>
```

to compute the password hash. Change the value of the `gateway.password` property
to the hash value for your password.

Example: if your password is `sup3rS3cr3t`:

```
$ gateway/bin/Linux/x86_64/mygateway -Hsup3rS3cr3t
61cba3bd7cc5bc6f3441a58c290e10a40f3cbcf6d1f538071d45a77e823273b0
```

Change the `gateway.password` property in `mygateway.properties` to:

```
gateway.password = 61cba3bd7cc5bc6f3441a58c290e10a40f3cbcf6d1f538071d45a77e823273b0
```

Next, change the value of the `webtunnel.domain` property to the domain UUID of your
my-devices.net reflector server account.

Optionally, you can also change other configuration properties, such as the
port of the internal web server (defaults to 8080).

Finally, run `mygateway`:

```
$ gateway/bin/Linux/x86_64/mygateway
```

and open its configuration web interface at
[http://localhost:8080](http://localhost:8080).

You should see this:

![Gateway Web User Interface - First Start][browser1]

Click the `[+]` button to create a new device connection. Your first device
can be to the built-in web interface of the Gateway, so that you will be able
to manage it remotely.

Enter the following information to make the Gateway's web user interface accessible remotely
via my-devices.net:

  - Name: Gateway
  - Device IP Address or Domain Name: 127.0.0.1
  - Forwarded TCP Ports: 8080
  - Device HTTP Server Port: 8080
  - Device Password: (leave empty)

![Gateway Web User Interface - Add Device][browser2]

Click `Save` to save your first Gateway connection.

You will now see it in the overview:

![Gateway Web User Interface - Device Added][browser3]

The Gateway should now be visible in your [my-devices.net Dashboard](https://reflector.my-devices.net).

You can now start adding other devices as well.


[browser1]: doc/images/browser1.png "Gateway Web User Interface - First Start"
[browser2]: doc/images/browser2.png "Gateway Web User Interface - Add Device"
[browser3]: doc/images/browser3.png "Gateway Web User Interface - Device Added"
