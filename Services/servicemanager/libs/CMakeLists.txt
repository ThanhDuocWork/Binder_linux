cmake_minimum_required(VERSION 3.0)
project(libs)

set(SOURCES
    binder/Parcel.cpp 
	binder/AppOpsManager.cpp 
	binder/Binder.cpp 
	binder/BpBinder.cpp 
	binder/BufferedTextOutput.cpp 
	binder/Debug.cpp 
	binder/IAppOpsCallback.cpp 
	binder/IAppOpsService.cpp 
	binder/IBatteryStats.cpp 
	binder/IInterface.cpp 
	binder/IMemory.cpp 
	binder/IPCThreadState.cpp 
	binder/IPermissionController.cpp 
	binder/IServiceManager.cpp 
	binder/MemoryBase.cpp 
	binder/MemoryDealer.cpp 
	binder/MemoryHeapBase.cpp 
	binder/PermissionCache.cpp 
	binder/IProcessInfoService.cpp 
	binder/ProcessInfoService.cpp 
	binder/ProcessState.cpp 
	binder/Static.cpp 
	binder/TextOutput.cpp
	binder/Status.cpp
	cutils/ashmem-dev.c 
	cutils/atomic.c 
	cutils/native_handle.c 
	cutils/process_name.c 
	cutils/properties.c 
	cutils/safe_iop.c 
	cutils/sched_policy.c 
	cutils/socket_inaddr_any_server.c 
	cutils/socket_local_client.c 
	cutils/socket_local_server.c 
	cutils/socket_loopback_client.c 
	cutils/socket_loopback_server.c 
	cutils/sockets.c 
	cutils/strlcpy.c 
	cutils/threads.c
	utils/BasicHashtable.cpp 
	utils/BlobCache.cpp 
	utils/CallStack.cpp 
	utils/FileMap.cpp 
	utils/JenkinsHash.cpp 
	utils/LinearTransform.cpp 
	utils/Log.cpp 
	utils/Looper.cpp 
	utils/misc.cpp 
	utils/NativeHandle.cpp 
	utils/Printer.cpp 
	utils/ProcessCallStack.cpp 
	utils/PropertyMap.cpp 
	utils/RefBase.cpp 
	utils/SharedBuffer.cpp 
	utils/Static.cpp 
	utils/StopWatch.cpp 
	utils/String16.cpp 
	utils/String8.cpp 
	utils/SystemClock.cpp 
	utils/Threads.cpp 
	utils/Timers.cpp 
	utils/Tokenizer.cpp 
	utils/Unicode.cpp 
	utils/VectorImpl.cpp
)

add_library(servicebinder SHARED ${SOURCES})

target_include_directories(servicebinder PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../
    )
 
install(TARGETS servicebinder DESTINATION ${CMAKE_SOURCE_DIR})