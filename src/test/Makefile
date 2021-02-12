SUBDIR := ctest cstest

.PHONY: all $(SUBDIR) maketestdb.sh

all: $(SUBDIR) maketestdb.sh
clean: $(SUBDIR)

$(SUBDIR):
	$(MAKE) -C $@ $(MAKECMDGOALS)

maketestdb.sh:
	chmod +x $@
