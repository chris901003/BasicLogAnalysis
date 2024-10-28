# 編譯器
CXX = g++

# 編譯選項
CXXFLAGS = -I/usr/include -L/usr/lib -lboost_system -lboost_random -std=c++17

CXXFLAGS2 = -O3 -Wall -shared -std=c++11 -fPIC -m64 $(PYBIND_INC_FLAGS) $(PYTHON_LIB_FLAGS)
PYBIND_INC_FLAGS = $(shell python3 -m pybind11 --includes)
PYTHON_LIB_FLAGS = $(shell python3-config --includes --ldflags)
PYTHON_SUF = $(shell python3-config --extension-suffix)

# 目標可執行文件
TARGET = main.out

# 源文件目錄
SRC_DIR = .
NETWORK_DIR = Network
UTILS_DIR = Utilities
DATA_DIR = Datas

# 將所有的 cpp 檔案自動加進來
SRCS = $(wildcard $(SRC_DIR)/*.cpp $(NETWORK_DIR)/*.cpp) $(wildcard $(UTILS_DIR)/*.cpp) $(shell find $(DATA_DIR) -name "*.cpp")

# 根據 .cpp 檔案自動生成 .o 檔案
OBJS = $(SRCS:.cpp=.o)

# 規則
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 編譯各個 .cpp 檔案
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 生成 python 模組
bind_test:
	$(CXX) $(CXXFLAGS2) -shared -fPIC -o ../python/test/bind_test$(PYTHON_SUF) Pybind/bind_test.cpp

# 測試
python_bind_test: bind_test
	pytest ../python/test/main_test.py

# ====== 片段測試 ======

# 生成 python 測試模組
bind_poisson_distributed_test:
	$(CXX) $(CXXFLAGS2) -shared -fPIC -o ../python/test/distributed/PoissonDistributedTest$(PYTHON_SUF) Pybind/DistributedTest/poisson_test.cpp

# 測試
partial_test: poisson_distributed_test
	@echo "===== Partial Test Finished ====="

poisson_distributed_test: bind_poisson_distributed_test
	pytest ../python/test/distributed/test.py
# ========================

# 清理
clean:
	rm -f $(OBJS) $(TARGET)
	find ../python -name '*.so' -type f -delete
	find ../python -name '__pycache__' -type d -exec rm -rf {} +
