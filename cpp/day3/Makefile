# ====================
#  Ubuntu C++ Makefile
#  支持 .cc 源码文件
# ====================

# 编译器（Ubuntu 默认 g++）
CXX = g++

# 编译选项：开启警告、C++11 标准
CXXFLAGS = -Wall -std=c++11

# 自动找到当前目录下所有 .cc 文件
SRC = $(wildcard *.cc)

# 把 .cc 文件名替换成可执行文件名（你也可以直接写：TARGET = myapp）
TARGET = $(patsubst %.cc, %, $(SRC))

# 默认编译
all: $(TARGET)

# 链接规则
%: %.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

# 清理编译产物
clean:
	rm -f $(TARGET)

# 伪目标
.PHONY: all clean
