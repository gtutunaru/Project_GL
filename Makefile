CC=g++
CFLAGS = -Wall -pedantic -std=c++11
CFLAGS += $(FOO) #il est possible d'utiliser make FOO=-DMAP pour pouvoir voir le traçage des appels aux constructeurs / destructeurs

MAIN= exec
SRCS= AttributeMeasure.cpp User.cpp Sensor.cpp Provider.cpp GovAgency.cpp Measure.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

MAP:
	make FOO=-DMAP #il est equivalent d'utiliser make MAP et make FOO=-DMAP

.PHONY: clean
clean:
	rm *.o $(MAIN)
