CC = gcc
CFLAGS = -Wall 
SOURCE = main.c
OUTPUT = myc
all: $(OUTPUT)
$(OUTPUT): $(SOURCE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCE)
clean:
	rm -f $(OUTPUT)
