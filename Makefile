# MASTER MAKEFILE

export EMPTY:=
export HIDE := @$(EMPTY)
export IGN  := -$(EMPTY)

export PROJECT_ROOT := $(PWD)
export INCLUDES = $(PROJECT_ROOT)/utils

UTILS := $(PROJECT_ROOT)/utils
_SUBDIRS := $(shell for dir in `ls $(PROJECT_ROOT)`; do [ -d $$dir ] && echo $$dir ; done)
SUBDIRS := $(filter-out $(notdir $(UTILS)),$(_SUBDIRS))

CLRDIRS := $(addsuffix .clean,$(SUBDIRS))

export CC = gcc
export CFLAGS = -I$(UTILS)


default: all

all: ECHO $(SUBDIRS)
	$(HIDE)echo ALL compile finished!

$(SUBDIRS):
	$(MAKE) -w -C $@
	$(HIDE)echo "<$@> was finished!"

$(CLRDIRS):
	$(MAKE) -w -C $(@:.clean=) clean

ECHO:
	$(HIDE)echo travers [$(SUBDIRS)]
	$(HIDE)echo start compiling...

clean: $(CLRDIRS)

.PHONY: default all $(SUBDIRS) clean $(CLRDIRS) ECHO

