# Makefile - X123_dll

ifndef CFG
CFG=Debug
endif
CC=gcc
CFLAGS=-m32 
CXX=g++
CXXFLAGS=$(CFLAGS)
ifeq "$(CFG)" "Debug"
CFLAGS+= -W -O0 -fexceptions -I..\DeviceIO/ -I.\ -g -fno-inline -D_DEBUG -D_CONSOLE 
LD=$(CXX) $(CXXFLAGS)
LDFLAGS=
LDFLAGS+= -L.\DeviceIO\
LIBS+=-lstdc++ -lm -static -llibusb
ifndef TARGET
TARGET=X123.dll
endif
ifeq "$(CFG)" "Release"
CFLAGS+= -W -O2 -fexceptions -I..\DeviceIO -I.\ -g -fno-inline -DNDEBUG -D_CONSOLE 
LD=$(CXX) $(CXXFLAGS)
LDFLAGS=
LDFLAGS+= -L..\DeviceIO\
#LIBS+=-lstdc++ -lm -static -llibusb
ifndef TARGET
TARGET=X123.dll
endif
endif
endif
ifndef TARGET
TARGET=X123.dll
endif
.PHONY: all
all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

%.res: %.rc
	$(RC) $(CPPFLAGS) -o $@ -i $<

SOURCE_FILES= \
	../ConsoleHelper.cpp \
	../DeviceIO/DP5Protocol.cpp \
	../DeviceIO/DP5Status.cpp \
	../DeviceIO/DppUtilities.cpp \
	../DeviceIO/ParsePacket.cpp \
	../DeviceIO/SendCommand.cpp \
	../DeviceIO/DppLibUsb.cpp \
	../stringex.cpp \
	../X123.cpp

HEADER_FILES= \
	../ConsoleHelper.h \
	../DeviceIO/DP5Protocol.h \
	../DeviceIO/DP5Status.h \
	../DeviceIO/DppConst.h \
	../DeviceIO/DppUtilities.h \
	../DeviceIO/ParsePacket.h \
	../DeviceIO/SendCommand.h \
	../DeviceIO/DppLibUsb.h \
	../DeviceIO/libusb.h \
	./stringex.h \
	./stringSplit.h \
	./X123.h

OBJ_FILES= \
	./ConsoleHelper.o \
	./DP5Protocol.o \
	./DP5Status.o \
	./DppUtilities.o \
	./ParsePacket.o \
	./SendCommand.o \
	./DppLibUsb.o \
	./stringex.o \
	./X123.o 

RESOURCE_FILES= \

SRCS=$(SOURCE_FILES) $(HEADER_FILES) $(RESOURCE_FILES) 

OBJS=$(patsubst %.rc,%.res,$(patsubst %.cxx,%.o,$(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(filter %.c %.cc %.cpp %.cxx %.rc,$(SRCS)))))))

$(TARGET): $(OBJS)
	$(LD) -shared $(LDFLAGS) -o $@ $(OBJ_FILES) $(LIBS)

.PHONY: clean
clean:
	-rm -f -v $(OBJS) $(TARGET) gccDppConsole.dep

.PHONY: depends
depends:
	-$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MM $(filter %.c %.cc %.cpp %.cxx,$(SRCS)) > gccDppConsole.dep

-include gccDppConsole.dep

