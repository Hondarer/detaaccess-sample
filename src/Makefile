SUBDIR := libsrc test

.PHONY: all $(SUBDIR)

all clean: $(SUBDIR)
install: libsrc

$(SUBDIR):
	$(MAKE) -C $@ $(MAKECMDGOALS)
