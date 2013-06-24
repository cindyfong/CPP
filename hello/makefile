# this is a makefile of the c++ project hello
# the standard c++ compiler in the Redhat linux is g++
# written by young on June 27th, 2009
      TARGET = .
          CC = g++
      CFLAGS = -g
      CFLAGC = -c
      
      MAINC = main.cpp
      HELLO = hello.cpp
        OBJ = hello.o
      
      INCLUDE = -I$(TARGET)
         EXEC = $(TARGET)/main
      
all: $(EXEC)
$(EXEC): $(OBJ) $(MAINC)
	$(CC) $(CFLAGS) $(OBJ) $(MAINC) $(INCLUDE) -o $@
	rm -f $(OBJ)
	@echo "<<<<<< $@ is created successfully! >>>>>>"
$(OBJ): $(HELLO)
	$(CC) $(CFLAGC) $(HELLO) -o $@
clean:
	rm -f $(EXEC)