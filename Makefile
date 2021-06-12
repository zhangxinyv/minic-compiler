TARGET:= minic

CFLAGS = -Wall -g
CFLAGS_TOOLS = -g
LD_FLAGS = -g

all: $(TARGET)

$(TARGET): minic_lex.o minic_yacc.o ast.o ir.o table.o main.o
	gcc $(LD_FLAGS) -o $@ $^ `pkg-config libgvc --cflags` `pkg-config libgvc --libs`

ast.o: ast.c ast.h
	gcc $(CFLAGS) -c -o $@ ast.c `pkg-config libgvc --cflags` `pkg-config libgvc --libs`

ir.o: ir.c ir.h table.h
	gcc $(CFLAGS) -c -o $@ ir.c `pkg-config libgvc --cflags` `pkg-config libgvc --libs`

table.o: table.c table.h minic_yacc.h
	gcc $(CFLAGS) -c -o $@ table.c `pkg-config libgvc --cflags` `pkg-config libgvc --libs`

minic_lex.o: minic_lex.c minic_yacc.h
	gcc $(CFLAGS_TOOLS) -c -o $@ minic_lex.c `pkg-config libgvc --cflags` `pkg-config libgvc --libs`

minic_lex.c minic_lex.h: minic_lex.l
	flex -o minic_lex.c --header-file=minic_lex.h minic_lex.l 

minic_yacc.o: minic_yacc.c minic_yacc.h minic_lex.h
	gcc $(CFLAGS_TOOLS) -c -o $@ minic_yacc.c `pkg-config libgvc --cflags` `pkg-config libgvc --libs`

minic_yacc.c minic_yacc.h: minic_yacc.y
	bison -d -o minic_yacc.c minic_yacc.y

main.o: main.c minic_yacc.h minic_lex.h
	gcc $(CFLAGS) -c -o $@ main.c `pkg-config libgvc --cflags` `pkg-config libgvc --libs`

tmpclean:
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf *.dSYM
	rm -f minic_lex.c minic_lex.h
	rm -f minic_yacc.c minic_yacc.h
	rm -f $(TARGET)

zip:
	tar --exclude *.tar.* -cvf $(TARGET).tar *
	gzip -f $(TARGET).tar
