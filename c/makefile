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
	@clang -std=c99 -Wall $(iname) -o $(oname) $(linkArgs) 

run: build
	@./$(oname) $(args)
	@rm $(oname)

link:
	@clang -std=c99 -Wall -W -c $(iname) $(linkArgs)

asm:
	@clang -std=c99 -Wall -W -S $(iname) $(linkArgs)
