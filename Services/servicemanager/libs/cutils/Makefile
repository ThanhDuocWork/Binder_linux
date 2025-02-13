CC = gcc
CFLAGS = -I../../ -I../include -c -fpic
LDFLAGS = -shared

SRCS =  \
		ashmem-dev.c \
		atomic.c \
		native_handle.c \
		process_name.c \
		properties.c \
		safe_iop.c \
		sched_policy.c \
		socket_inaddr_any_server.c \
		socket_local_client.c \
		socket_local_server.c \
		socket_loopback_client.c \
		socket_loopback_server.c \
		sockets.c \
		strlcpy.c \
		threads.c
OBJS = $(SRCS:.c=.o)
LIBS =  \
		libashmem-dev.so \
		libatomic.so \
		libnative_handle.so \
		libprocess_name.so \
		libproperties.so \
		libsafe_iop.so \
		libsched_policy.so \
		libsocket_inaddr_any_server.so \
		libsocket_local_client.so \
		libsocket_local_server.so \
		libsocket_loopback_client.so \
		libsocket_loopback_server.so \
		libsockets.so \
		libstrlcpy.so \
		libthreads.so
	
all: $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@
libashmem-dev.so: ashmem-dev.o
	$(CC) $(LDFLAGS) -o $@ $<
libatomic.so: atomic.o
	$(CC) $(LDFLAGS) -o $@ $<
libnative_handle.so: native_handle.o
	$(CC) $(LDFLAGS) -o $@ $<
libprocess_name.so: process_name.o
	$(CC) $(LDFLAGS) -o $@ $<
libproperties.so: properties.o
	$(CC) $(LDFLAGS) -o $@ $<
libsafe_iop.so: safe_iop.o
	$(CC) $(LDFLAGS) -o $@ $<
libsched_policy.so: sched_policy.o
	$(CC) $(LDFLAGS) -o $@ $<
libsocket_inaddr_any_server.so: socket_inaddr_any_server.o
	$(CC) $(LDFLAGS) -o $@ $<
libsocket_local_client.so: socket_local_client.o
	$(CC) $(LDFLAGS) -o $@ $<
libsocket_local_server.so: socket_local_server.o
	$(CC) $(LDFLAGS) -o $@ $<
libsocket_loopback_client.so: socket_loopback_client.o
	$(CC) $(LDFLAGS) -o $@ $<
libsocket_loopback_server.so: socket_loopback_server.o
	$(CC) $(LDFLAGS) -o $@ $<
libsockets.so: sockets.o
	$(CC) $(LDFLAGS) -o $@ $<
libstrlcpy.so: strlcpy.o
	$(CC) $(LDFLAGS) -o $@ $<
libthreads.so: threads.o
	$(CC) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) $(LIBS)