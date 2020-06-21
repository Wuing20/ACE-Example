.PYTHON: clean

CC=g++
CFLAGS=-Wall -O -g -lACE -lpthread

src=$(wildcard *.cpp)
obj=$(patsubst %.c,%.o,$(src))
target=SYNCRequest

$(target):$(obj)
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	-rm -f $(target)
	-rm -f *.o
