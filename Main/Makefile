WorkspaceRoot=$(shell FindRootPath.sh $(CURDIR))
include $(WorkspaceRoot)/Make/Make.Configuration

LdFlags += -lstdc++

CXX 	= $(C++)

ExeFile=main.exe
include $(WorkspaceRoot)/Make/Make.Exec
