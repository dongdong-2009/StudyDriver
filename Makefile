WorkspaceRoot=$(shell FindRootPath.sh $(CURDIR))
include $(WorkspaceRoot)/Make/Make.Configuration

SharedLibVer = 0
BuildDir	= $(CURDIR)/Build
BuildLibDir = $(BuildDir)/Lib

SubDirs=Main SetConsole Sbull Scull

all: $(SubDirs)
	install -p -m 0755 Build/Main/main.exe $(CURDIR)
	install -p -m 0755 Build/SetConsole/SetConsole.exe $(CURDIR)

load:
	$(MAKE) -C Scull load

unload:
	$(MAKE) -C Scull unload

.PHONY: all load unload

include $(WorkspaceRoot)/Make/Make.SubDirs