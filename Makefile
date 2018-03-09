#
# Makefile
#
# Makefile for my-devices Gateway
#

POCO_BASE = $(shell dirname `pwd`)/sdk
PROJECT_BASE = $(shell dirname `pwd`)

include $(POCO_BASE)/build/rules/global

WEBTUNNEL_ENABLE_TLS = 1

# Where to find the PageCompiler executable
PAGECOMPILER = $(POCO_BASE)/PageCompiler/bin/$(POCO_HOST_OSNAME)/$(POCO_HOST_OSARCH)/cpspc
FILE2PAGE = $(POCO_BASE)/PageCompiler/File2Page/bin/$(POCO_HOST_OSNAME)/$(POCO_HOST_OSARCH)/f2cpsp

ifdef WEBTUNNEL_ENABLE_TLS
CXXFLAGS += -DWEBTUNNEL_ENABLE_TLS
tlslibs = PocoNetSSL PocoCrypto
SYSLIBS += -lssl -lcrypto -lz -ldl
endif

ifeq ($(OSNAME),Linux)
SYSLIBS += -lcrypt
endif

objects = GatewayServer WebTunnelAgent DeviceManager Utility PageController \
	IndexPage IndexPageController \
	DevicePage DevicePageController \
	Stylesheet \
	FavIcon \
	Gradient \
	HeaderLogo HeaderLogoX2 \
	FooterLogo FooterLogoX2 \
	PlusIcon PlusIconX2 \
	MinusIcon MinusIconX2

target         = mygateway
target_version = 1
target_libs    = PocoWebTunnel PocoNetSSL PocoNet PocoCrypto PocoUtil PocoXML PocoFoundation

include $(POCO_BASE)/build/rules/exec

# Rule for runnning PageCompiler
src/%.cpp: src/%.cpsp html/header.inc html/footer.inc html/template.inc
	@echo "** Compiling Page" $<
	$(PAGECOMPILER) $<

src/%.cpsp: res/%.js
	@echo "** Compiling Resource" $<
	$(FILE2PAGE) --namespace=MyDevices::Gateway $< -o$@

src/%.cpsp: res/%.css
	@echo "** Compiling Resource" $<
	$(FILE2PAGE) --namespace=MyDevices::Gateway $< -o$@

src/%.cpsp: res/%.png
	@echo "** Compiling Resource" $<
	$(FILE2PAGE) --namespace=MyDevices::Gateway $< -o$@

src/%.cpsp: res/%.ico
	@echo "** Compiling Resource" $<
	$(FILE2PAGE) --namespace=MyDevices::Gateway $< -o$@
