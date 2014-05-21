CXX=g++
CXX_FLAGS=-Wall -g
LIBS=-pthread

TARGET=sequencing-ants

INTERFACES=common edge node ranking solution

SUBTARGETS=ant graph
TARGET_FILES=$(SUBTARGETS) main
HEADER_FILES=$(SUBTARGETS) $(INTERFACES)

SOURCES=$(addprefix src/, $(addsuffix .cpp, $(TARGET_FILES)))
HEADERS=$(addprefix src/, $(addsuffix .hpp, $(HEADER_FILES)))
OBJS=$(addprefix obj/, $(addsuffix .o, $(TARGET_FILES)))

all: init $(TARGET)

init:
	-mkdir -p obj

$(TARGET): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(LIBS) -o $@ $(OBJS)

obj/%.o: src/%.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	-rm -rf obj $(TARGET)
