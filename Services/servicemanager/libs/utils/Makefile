CC = gcc
CFLAGS = -I../include -I../../ -c -fpic
LDFLAGS = -shared

SRCS =  BasicHashtable.cpp \
		BlobCache.cpp \
		CallStack.cpp \
		FileMap.cpp \
		JenkinsHash.cpp \
		LinearTransform.cpp \
		Log.cpp \
		Looper.cpp \
		misc.cpp \
		NativeHandle.cpp \
		Printer.cpp \
		ProcessCallStack.cpp \
		PropertyMap.cpp \
		RefBase.cpp \
		SharedBuffer.cpp \
		Static.cpp \
		StopWatch.cpp \
		String16.cpp \
		String8.cpp \
		SystemClock.cpp \
		Threads.cpp \
		Timers.cpp \
		Tokenizer.cpp \
		Unicode.cpp \
		VectorImpl.cpp
OBJS = $(SRCS:.cpp=.o)
LIBS =  libBasicHashtable.so \
		libBlobCache.so \
		libCallStack.so \
		libFileMap.so \
		libJenkinsHash.so \
		libLinearTransform.so \
		libLog.so \
		libLooper.so \
		libmisc.so \
		libNativeHandle.so \
		libPrinter.so \
		libProcessCallStack.so \
		libPropertyMap.so \
		libRefBase.so \
		libSharedBuffer.so \
		libStatic.so \
		libStopWatch.so \
		libString16.so \
		libString8.so \
		libSystemClock.so \
		libThreads.so \
		libTimers.so \
		libTokenizer.so \
		libUnicode.so \
		libVectorImpl.so

all: $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@
libBasicHashtable.so: BasicHashtable.o
	$(CC) $(LDFLAGS) -o $@ $<
libBlobCache.so: BlobCache.o
	$(CC) $(LDFLAGS) -o $@ $<
libCallStack.so: CallStack.o
	$(CC) $(LDFLAGS) -o $@ $<
libFileMap.so: FileMap.o
	$(CC) $(LDFLAGS) -o $@ $<
libJenkinsHash.so: JenkinsHash.o
	$(CC) $(LDFLAGS) -o $@ $<
libLinearTransform.so: LinearTransform.o
	$(CC) $(LDFLAGS) -o $@ $<
libLog.so: Log.o
	$(CC) $(LDFLAGS) -o $@ $<
libLooper.so: Looper.o
	$(CC) $(LDFLAGS) -o $@ $<
libmisc.so: misc.o
	$(CC) $(LDFLAGS) -o $@ $<
libNativeHandle.so: NativeHandle.o
	$(CC) $(LDFLAGS) -o $@ $<
libPrinter.so: Printer.o
	$(CC) $(LDFLAGS) -o $@ $<
libProcessCallStack.so: ProcessCallStack.o
	$(CC) $(LDFLAGS) -o $@ $<
libPropertyMap.so: PropertyMap.o
	$(CC) $(LDFLAGS) -o $@ $<
libRefBase.so: RefBase.o
	$(CC) $(LDFLAGS) -o $@ $<
libSharedBuffer.so: SharedBuffer.o
	$(CC) $(LDFLAGS) -o $@ $<
libStatic.so: Static.o
	$(CC) $(LDFLAGS) -o $@ $<
libStopWatch.so: StopWatch.o
	$(CC) $(LDFLAGS) -o $@ $<
libString16.so: String16.o
	$(CC) $(LDFLAGS) -o $@ $<
libString8.so: String8.o
	$(CC) $(LDFLAGS) -o $@ $<
libSystemClock.so: SystemClock.o
	$(CC) $(LDFLAGS) -o $@ $<
libThreads.so: Threads.o
	$(CC) $(LDFLAGS) -o $@ $<
libTimers.so: Timers.o
	$(CC) $(LDFLAGS) -o $@ $<
libTokenizer.so: Tokenizer.o
	$(CC) $(LDFLAGS) -o $@ $<
libUnicode.so: Unicode.o
	$(CC) $(LDFLAGS) -o $@ $<
libVectorImpl.so: VectorImpl.o
	$(CC) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) $(LIBS)