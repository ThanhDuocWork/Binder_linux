CC = gcc
CFLAGS = -I../../ -I../include -c -fpic
LDFLAGS = -shared

SRCS =  \
	

OBJS = $(SRCS:.cpp=.o)
LIBS =  \
	libParcel.so \
	libAppOpsManager.so \
	libBinder.so \
	libBpBinder.so \
	libBufferedTextOutput.so \
	libDebug.so \
	libIAppOpsCallback.so \
	libIAppOpsService.so \
	libIBatteryStats.so \
	libIInterface.so \
	libIMemory.so \
	libIPCThreadState.so \
	libIPermissionController.so \
	libIServiceManager.so \
	libMemoryBase.so \
	libMemoryDealer.so \
	libMemoryHeapBase.so \
	libPermissionCache.so \
	libIProcessInfoService.so \
	libProcessInfoService.so \
	libProcessState.so \
	libStatic.so \
	libTextOutput.so
	
all: $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@
libParcel.so: Parcel.o
	$(CC) $(LDFLAGS) -o $@ $<
libAppOpsManager.so: AppOpsManager.o
	$(CC) $(LDFLAGS) -o $@ $<
libBinder.so: Binder.o
	$(CC) $(LDFLAGS) -o $@ $<
libBpBinder.so: BpBinder.o
	$(CC) $(LDFLAGS) -o $@ $<
libBufferedTextOutput.so: BufferedTextOutput.o
	$(CC) $(LDFLAGS) -o $@ $<
libDebug.so: Debug.o
	$(CC) $(LDFLAGS) -o $@ $<
libIAppOpsCallback.so: IAppOpsCallback.o
	$(CC) $(LDFLAGS) -o $@ $<
libIAppOpsService.so: IAppOpsService.o
	$(CC) $(LDFLAGS) -o $@ $<
libIBatteryStats.so: IBatteryStats.o
	$(CC) $(LDFLAGS) -o $@ $<
libIInterface.so: IInterface.o
	$(CC) $(LDFLAGS) -o $@ $<
libIMemory.so: IMemory.o
	$(CC) $(LDFLAGS) -o $@ $<
libIPCThreadState.so: IPCThreadState.o
	$(CC) $(LDFLAGS) -o $@ $<
libIPermissionController.so: IPermissionController.o
	$(CC) $(LDFLAGS) -o $@ $<
libIServiceManager.so: IServiceManager.o
	$(CC) $(LDFLAGS) -o $@ $<
libMemoryBase.so: MemoryBase.o
	$(CC) $(LDFLAGS) -o $@ $<
libMemoryDealer.so: MemoryDealer.o
	$(CC) $(LDFLAGS) -o $@ $<
libMemoryHeapBase.so: MemoryHeapBase.o
	$(CC) $(LDFLAGS) -o $@ $<
libPermissionCache.so: PermissionCache.o
	$(CC) $(LDFLAGS) -o $@ $<
libIProcessInfoService.so: IProcessInfoService.o
	$(CC) $(LDFLAGS) -o $@ $<
libProcessInfoService.so: ProcessInfoService.o
	$(CC) $(LDFLAGS) -o $@ $<
libProcessState.so: ProcessState.o
	$(CC) $(LDFLAGS) -o $@ $<
libStatic.so: Static.o
	$(CC) $(LDFLAGS) -o $@ $<
libTextOutput.so: TextOutput.o
	$(CC) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) $(LIBS)