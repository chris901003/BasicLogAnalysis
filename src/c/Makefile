# 編譯器
CXX = g++

# 編譯選項
CXXFLAGS = -std=c++17

# 目標可執行文件
TARGET = main.out

# 源文件目錄
SRC_DIR = .
POISSON_DIR = Poisson

# 將所有的 cpp 檔案自動加進來
SRCS = $(wildcard $(SRC_DIR)/*.cpp $(POISSON_DIR)/*.cpp)

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
