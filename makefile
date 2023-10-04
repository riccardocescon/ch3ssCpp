CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = main.o Utils.o Cell.o Layer.o Map.o 
TARGET = stacktest

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~