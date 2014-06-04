CXX=g++-4.9
CXX_FLAGS=-Wall -g -std=c++11
LIBS=-pthread

TARGET=sequencing-ants

INTERFACES=common aco_strategy notifiable node metaheuristic aco_parameters

SUBTARGETS=ant graph edge random_number_generator aco ranking solution aco_sequential_strategy aco_parallel_strategy ant_thread

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
