# ====================
#  Ubuntu C++ Makefile 适配valgrind memcheck
#  支持 .cc 源码文件
# ====================

# 编译器（Ubuntu 默认 g++）
CXX = g++

# 编译选项：-g生成调试符号 -O0关闭优化(关键给memcheck用)、开启警告、C++11
CXXFLAGS = -Wall -std=c++11 -g -O0

# valgrind memcheck固定参数（全套泄漏检测）
MEMCHECK = valgrind
MEM_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

# 自动找到当前目录下所有 .cc 文件
SRC = $(wildcard *.cc)

# 把 .cc 文件名替换成可执行文件名
TARGET = $(patsubst %.cc, %, $(SRC))

# 默认编译
all: $(TARGET)

# 链接规则
%: %.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

# 一键内存检测：make memcheck（逐个检测所有可执行程序）
memcheck: all
	@for exe in $(TARGET);do \
		echo "===== 开始检测 $$exe 内存 =====";\
		$(MEMCHECK) $(MEM_FLAGS) ./$$exe;\
	done

# gdb调试：make debug 单个程序，例 make debug TARGET=main
debug: all
	gdb ./$(TARGET)

# 清理编译产物
clean:
	rm -f $(TARGET)

# 伪目标补充memcheck、debug
.PHONY: all clean memcheck debug
