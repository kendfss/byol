oname ?= main
iname ?= $(addsuffix .c,$(oname))
args ?= $(filter-out $@,$(MAKECMDGOALS))

ifeq ($(oname),main)
	linkArgs ?= -ledit -lm
endif
ifeq ($(oname),byol)
	linkArgs ?= -ledit -lm
endif

build:
	@clang -s -std=c99 -Wall $(iname) -o $(oname) $(linkArgs) 

debug:
	oname=$(oname)dbv
	@clang -ggdb3 -std=c99 -Wall $(iname) -o $(oname) $(linkArgs) 
	@gdb $(oname)

run: build
	@./$(oname) $(args)
	@rm $(oname)

link:
	@clang -std=c99 -Wall -W -c $(iname) $(linkArgs)

asm:
	@clang -std=c99 -Wall -W -S $(iname) $(linkArgs)
