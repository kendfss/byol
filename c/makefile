fname?=main
oname=$(fname)
iname=$(addsuffix .c,$(fname))
args?=$(filter-out $@,$(MAKECMDGOALS))

build:
	@clang -std=c99 -Wall $(iname) -o $(oname)

run: build
	@./$(oname) $(args)
	@rm $(oname)

link:
	clang -W -Wall -std=c99 -c  $(fname).c

asm:
	clang -W -Wall -std=c99 -S $(fname).c
