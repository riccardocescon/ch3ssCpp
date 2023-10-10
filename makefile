CXX := g++
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include
CXXFLAGS := -std=c++14 -I$(INCLUDE_DIR) -g
TARGET := Ch3ss

# Trova tutti i file .cpp nelle sotto-cartelle
SRCS := $(wildcard $(SRC_DIR)/Pieces/*.cpp) \
	$(wildcard $(SRC_DIR)/Enviroment/*.cpp) \
	$(wildcard $(SRC_DIR)/API/*.cpp) \
	$(wildcard $(SRC_DIR)/*.cpp)
  
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Crea automaticamente le directory di destinazione
$(shell mkdir -p $(dir $(OBJS)))

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Aggiungi il nome del tuo eseguibile per i test unitari
TEST_TARGET := test_ch3ss
TEST_SRC_DIR := test
TEST_SRCS := $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRCS))

# Crea automaticamente le directory di destinazione per gli oggetti dei test
$(shell mkdir -p $(dir $(TEST_OBJS)))

# Aggiungi la definizione TESTING quando compili il test
TEST_CXXFLAGS := $(CXXFLAGS) -DTESTING

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	$(CXX) $(TEST_CXXFLAGS) -o $@ $^ -lgtest -lgtest_main -pthread

$(OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp
	$(CXX) $(TEST_CXXFLAGS) -c -o $@ $<

.PHONY: clean test

clean:
	rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS)

test: $(TEST_TARGET)
	./$(TEST_TARGET)