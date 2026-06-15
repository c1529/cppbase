# ====================
# 新增：log4cpp 支持 + 自动生成配置文件
# ====================
INC_FLAGS += -I/usr/local/include
LDFLAGS  += -L/usr/local/lib
LDLIBS   += -llog4cpp -lpthread

# 配置文件路径
CFG_DIR  = cfg
CFG_FILE = $(CFG_DIR)/log4cfg

# ====================
#  Ubuntu C++ Makefile 适配valgrind memcheck
#  支持 .cc 源码文件
# ====================

# 编译器（Ubuntu 默认 g++）
CXX = g++

# 编译选项：-g生成调试符号 -O0关闭优化(关键给memcheck用)、开启警告、C++11
CXXFLAGS = -Wall -std=c++17 -g -O0 $(INC_FLAGS)

# valgrind memcheck固定参数（全套泄漏检测）
MEMCHECK = valgrind
MEM_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

# 自动找到当前目录下所有 .cc 文件
SRC = $(wildcard *.cc)

# 把 .cc 文件名替换成可执行文件名
TARGET = $(patsubst %.cc, %, $(SRC))

# 默认编译（先确保配置文件存在）
all: check_cfg $(TARGET)

# 链接规则
%: %.cc
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

# 检查并自动生成 log4cfg（解决“文件不存在”报错）
check_cfg:
	@mkdir -p $(CFG_DIR)
	@if [ ! -f $(CFG_FILE) ]; then \
		echo "log4cpp.rootCategory=DEBUG, console" > $(CFG_FILE); \
		echo "log4cpp.appender.console=ConsoleAppender" >> $(CFG_FILE); \
		echo "log4cpp.appender.console.layout=PatternLayout" >> $(CFG_FILE); \
		echo "log4cpp.appender.console.layout.ConversionPattern=%d [%p] %m%n" >> $(CFG_FILE); \
		echo "===== 自动生成 $(CFG_FILE) ====="; \
	fi

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

# 伪目标
.PHONY: all clean memcheck debug check_cfg
