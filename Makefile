
TARGET = gngeo

CC = ../gcc-arm-8.2-2018.08-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc
CXX = ../gcc-arm-8.2-2018.08-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++
STRIP = ../gcc-arm-8.2-2018.08-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-strip

SOURCES = src/
CFILES = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.cpp))
AFILES = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.s))
OFILES = $(CFILES:.c=.o) $(CPPFILES:.cpp=.o) $(AFILES:.s=.o)

CFLAGS = -I$(shell pwd)/src/include/ -I$(shell pwd)/src/include/SDL -marm -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard -O3 -march=armv7ve -ffast-math -fomit-frame-pointer -fno-strength-reduce
CXXFLAGS = $(CFLAGS)

LDFLAGS = -L$(shell pwd)/dependency/release/nvr/i2m/common/glibc/8.2.1/cust_libs/dynamic/ -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
LDFLAGS += -L$(shell pwd)/dependency/release/nvr/i2m/common/glibc/8.2.1/mi_libs/dynamic/ -lmi_common -lmi_sys -lmi_disp -lmi_panel -lmi_gfx -lmi_divp -lmi_ao -lmad -lfreetype
LDFLAGS += -lm -lz

$(TARGET): $(OFILES)
	$(CXX) $(OFILES) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s 
	$(CXX) $(ASFLAGS) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OFILES)
