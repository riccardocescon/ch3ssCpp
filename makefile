CXX := g++
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include
CXXFLAGS := -std=c++11 -I$(INCLUDE_DIR) -g
TARGET := Ch3ss

# Trova tutti i file .cpp nelle sotto-cartelle
SRCS :=	$(wildcard $(SRC_DIR)/Pieces/*.cpp) \
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

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJS)