##**************************************************************************
##------------------------------------------------------
##               make           - build
##               make debug     - debug build
##               make install   - install library
##               make dinstall  - install debug library
##               make clean     - delete generated files
##
##------------------------------------------------------
##**************************************************************************

############# Project Paths ########
srcdir = src
objdir = obj
bindir = bin


############# GCC Compiler Options ########
CC = gcc
CFLAGS = -Wall -g -c -std=c99


############# GNU Command ########
RM = del
RD = rd 
MV = move
CP = copy 
MK = make
MKDIR = mkdir


################# Target and Objects VARs ############
TARGET = main.exe
OBJS = $(SRCS:.c=.o) $(HDRS)
#OBJS = $(subst .c,.o,$(wildcard *.c))


################## C Source Files ######################
HDRS = 						\
	$(srcdir)\common.h

#SRCS = $(wildcard *.c)
SRCS = \
	$(srcdir)\main.c		\
	$(srcdir)\math.c		\
	$(srcdir)\pointer.c		\
	$(srcdir)\array.c 		\
	$(srcdir)\debug.c 	\
	$(srcdir)\cast.c		\
	$(srcdir)\sizeof.c		\
	$(srcdir)\typedef.c		\
	$(srcdir)\jump.c		\
	$(srcdir)\signal.c		\
	$(srcdir)\time.c		\
	$(srcdir)\statemachine.c	\
	$(srcdir)\stack.c

	
################### Default build Target Rules ##################
all: __prebuild__ __build__ __postbuild__
	@echo ----------------------------------------------------------------
#	@echo Run $(bindir)\$(TARGET)
#	@echo ----------------------------------------------------------------
#	@$(bindir)\$(TARGET)

__prebuild__:
	@echo ----------------------------------------------------------------
	@echo "********************* Build started ****************************"

__build__: __opts__ $(OBJS)
	@echo ----------------------------------------------------------------
	@echo "******************** Creating $(TARGET) **************************"	
	@if not exist $(bindir) $(MKDIR) $(bindir)
	@$(CC) -o $(bindir)\$(TARGET) $(OBJS)
	@echo $(bindir)\$(TARGET)

__postbuild__: __copy__ 
	@echo ----------------------------------------------------------------
	@echo "********************* Build finished ***************************"

__opts__:
	@echo *** Compiler: $(CC)
	@echo *** Compiler options: $(CFLAGS)
	@echo ----------------------------------------------------------------
	@echo "******************** Code generation ***************************"

__copy__:
	@echo ----------------------------------------------------------------
	@echo "******************** Installing files **************************"
	@if not exist $(objdir) $(MKDIR) $(objdir)	
	@$(CP)  $(srcdir)\*.o	$(objdir)
	@-$(RM) $(srcdir)\*.o

	
############# Pattern Rule ####################
$(OBJS):
%.o:%.c
	@echo Compiling $< 
	@$(CC) -o $@ $(CFLAGS) $<

	
################### Make debug/install/dinstall/clean ##################
debug:
	@echo ************* nothing to be done for debug **************
#	@$(MK) DEBUG=1

install: __prebuild__ 
	@$(MK) __build__
	@$(MK) __postbuild__

dinstall: __prebuild__ 
	@$(MK) __build__
	@$(MK) __postbuild__

clean:
	@echo ----------------------------------------------------------------
	@echo "********************** Cleaning up *****************************"
	@if exist $(srcdir)\*.o $(RM) $(srcdir)\*.o 
	@if exist $(srcdir)\*.exe $(RM) $(srcdir)\*.exe
	
	@if exist $(objdir)\*.o $(RM) $(objdir)\*.o
	@if exist $(objdir) $(RD) $(objdir)
	@if exist $(bindir)\*.exe $(RM) $(bindir)\*.exe
	@if exist $(bindir) $(RD) $(bindir)

	
################### Make run ##################
.PHONY:run
run:
	$(bindir)\$(TARGET)
	
	
################### Make LS/DIR ##################
ls:
	@dir /b

	

###################################################
###################################################
#				Make Study
###################################################
###################################################

study: def eq exist
	@echo.
	@echo ---------Make Study----------
	@echo.
	
#################  ifdef/ifndef ###################
def:
ifdef __WILDCARD__
#ifndef CC
	@echo ifdef is true
else
	@echo ifdef is false
endif


#################  ifeq/ifneq ###################
eq:
ifeq ($(CC),gcc)
#ifeq "$(CC)""gcc"
#ifeq '$(CC)''gcc)'
#ifeq "$(CC)"'gcc)'
#ifeq '$(CC)'"gcc)"
	@echo ifeq is true
else
	@echo ifeq is false
endif


#################  if exist/if not exist ###################
exist:
	@if exist hello.c @echo if-exist is true
	@echo if-exist is false
	
	@if not exist hello.c @echo if-not-exist is true










