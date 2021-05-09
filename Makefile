OUTPUTFILE=main
FILES=main.cpp Dog.cpp Animal.cpp Cat.cpp
FLAGS=-lpthread -I. # this last one is important for cereal

#default, first target
all: $(OUTPUTFILE)

# same as typing "main: build"
$(OUTPUTFILE): build 
	./$(OUTPUTFILE)

#rule to build hello.exe
build: $(FILES)
	g++ -o $(OUTPUTFILE) $(FILES) $(FLAGS)
	
clean:
	rm -f $(OUTPUTFILE)

# not real files, don't look for them
.PHONY: all build clean
