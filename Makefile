CC=arm-none-eabi-gcc

MACH=cortex-m4
BUILD_DIR = build

CFLAGS=-c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
SFLAGS=-S -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
LDFLAGS = -mcpu=$(MACH) -mthumb --specs=nano.specs --specs=nosys.specs -T stm32_Myls.ld -Wl,-Map=$(BUILD_DIR)/final.map

SRCS = main.c led.c stm32_startupByMe.c syscalls.c

OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))
ASMS = $(patsubst %.c, $(BUILD_DIR)/%.s, $(SRCS))


all: $(BUILD_DIR) $(ASMS) $(BUILD_DIR)/final.elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile: .c -> .o
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Assembly output: .c -> .s
$(BUILD_DIR)/%.s: %.c
	$(CC) $(SFLAGS) -o $@ $<

$(BUILD_DIR)/final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)