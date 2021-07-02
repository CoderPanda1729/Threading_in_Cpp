# declara varialbe

CC=g++

CFLAGS= -std=c++11 -pthread

# this target will compile all the file


all: 
	
mutex :
	 $(CC) $(CFLAGS) mutex.cpp

function_pointer:
	$(CC) $(CFLAGS) function_pointer.cpp

functional_thread:
	 $(CC) $(CFLAGS) functional_thread.cpp

join_detach_joinable:
	 $(CC) $(CFLAGS) join_detach_joinable.cpp

Mutex_try_lock:
	 $(CC) $(CFLAGS) Mutex_try_lock.cpp
	
std_try_lock:
	$(CC) $(CFLAGS) std_try_lock.cpp
	
timed_mutex:
	$(CC) $(CFLAGS) timed_mutex.cpp

recursive_mutex:
	$(CC) $(CFLAGS) recursive_mutex.cpp


      
