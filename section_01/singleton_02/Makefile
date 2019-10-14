#SUB MAKEFILE

SELF_DIR := $(shell pwd)

RUBBISH := *.o *.d

TT ?=$(EMTPY)

ifeq ($(strip $(TT)),$(EMPTY))
  TT := auto_demo
endif

ALL_FILES := $(shell for _file in `ls $(SELF_DIR)`; do echo $$_file ; done)
SRC_FILES := $(filter %.c,$(ALL_FILES))
TARGET_FILES := $(SRC_FILES:.c=.o)

default: $(TT)

$(TT):$(TARGET_FILES)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	$(HIDE)rm -rf $(RUBBISH) $(TT)
