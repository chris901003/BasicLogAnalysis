# 編譯器
CXX = g++

# 編譯選項
CXXFLAGS = -I/opt/homebrew/opt/boost/include -L/opt/homebrew/opt/boost/lib -lboost_system -lboost_random -std=c++17

# 目標可執行文件
TARGET = main.out

# 源文件目錄
SRC_DIR = .
POISSON_DIR = Poisson
UTILS_DIR = Utilities
DATA_DIR = Datas

# 將所有的 cpp 檔案自動加進來
SRCS = $(wildcard $(SRC_DIR)/*.cpp $(POISSON_DIR)/*.cpp) $(wildcard $(UTILS_DIR)/*.cpp) $(shell find $(DATA_DIR) -name "*.cpp")

# 根據 .cpp 檔案自動生成 .o 檔案
OBJS = $(SRCS:.cpp=.o)

# 規則
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 編譯各個 .cpp 檔案
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(OBJS) $(TARGET)
