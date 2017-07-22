###################### Makefile Begin ###########################
CC = gcc
CFLAGS = -g -Wall
OBJS = main.o 
TARGET = main.exe

main:$(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@main.exe
	
%.o:%.c
	@echo compiling $<
	@$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	del *.o *.exe

###################### Makefile End ###########################

	