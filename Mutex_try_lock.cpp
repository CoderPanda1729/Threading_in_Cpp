// TOPIC:  std :: try_lock() on Mutex in C++11 Threading

// 0. try_lock(),Tries to lock the  mutex .Returns immediately . On Successful lock acquisition returns true otherwise returns false.
// 1. If try lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
// 2.If try_lock is called again by the same thread which owns the mutex, the behavious is undefined.
// It is a lock situation wiht undefined behaviour. (if you want to be able to lock the same mutex by same 
// thread more than one time the go for recursive_mutex)

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int counter=0;
std:: mutex mtx;

void increaseTheCounterFor100000Times(){

    for(int i =0;i<100000;i++){
    	if(mtx.try_lock()){
    		++counter;
    		mtx.unlock();  //releasing the lock 
    }


  }
}
int main(){

   std::thread t1(increaseTheCounterFor100000Times);
   std:: thread t2(increaseTheCounterFor100000Times);

   t1.join();
   t2.join();


   cout<<"counter could increase upto "<<counter<<endl;  // the value of counter will always be less than 200000,
   // as t1 and t2 cannot increment counter simulaneously , if one is incrementing then other cannot be get locked to increment counter value.

   return 0;

}