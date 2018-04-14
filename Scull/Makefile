# Comment/uncomment the following line to disable/enable debugging
#DEBUG = y

# Add your debugging flag (or not) to CFLAGS
DEBUG=y
ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSCULL_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

EXTRA_CFLAGS += $(DEBFLAGS) -I$(LDDINC)

ifneq ($(KERNELRELEASE),)
    # call from kernel build system
    scull-objs := main.o pipe.o access.o
    obj-m	:= scull.o
else
    KERNELDIR ?= /lib/modules/$(shell uname -r)/build
    
modules: $(SourceFiles)
	$(MAKE) -C $(KERNELDIR) M=$(CURDIR) LDDINC=$(CURDIR)/../examples/include modules
	
load:
	./scull_load

unload:
	./scull_unload
	
endif

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

depend .depend dep:
	$(CC) $(EXTRA_CFLAGS) -M *.c > .depend


ifeq (.depend,$(wildcard .depend))
	include .depend
endif
