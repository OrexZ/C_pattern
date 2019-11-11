#SUB MAKEFILE

SECTION_DIR := $(shell pwd)
SUBDIRS := $(shell for dir in `ls $(SECTION_DIR)`; do [ -d $$dir ] && echo $$dir ; done)
CLRDIRS := $(addsuffix .clean,$(SUBDIRS))
TARGETS := $(SUBDIRS:%=%.o)

default: $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -w -C $@ TT=$@

clean: $(CLRDIRS)

$(CLRDIRS):
	$(MAKE) -w -C $(@:.clean=) clean TT=$(@:.clean=)

.PHONY: default $(SUBDIRS) clean

