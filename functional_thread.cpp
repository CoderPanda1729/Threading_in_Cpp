// questions
 // 1. What do you understand by thread and give one example in C++?

// Answer:
//  0. In every application there is  a default thread which is main()  , in side with we create other threads

//  1. A thread is also known as lightweight process. Ideas is achieve parallelism by dividing a process into multiple threads.

//    For example: 
//     a) The browser has multiple tabs that can be different threads.
//     b) MS word must be using multiple threads. one thread to fromat the text, another thread to process inputs (spell checker) 
//     c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)


// WAYS TO CREATE THREADS IN C+=11
// 1. Function Pointers
// 2.Lambda Function
// 3.Functors
// 4/Member Functions
// 5. Static Member Function

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std :: chrono;

typedef unsigned long long ull;

ull OddSum=0;
ull EvenSum=0;


void findEven(ull start, ull end){
    for(ull i=start;i<=end;i++){
        if((i&1)==0){
            EvenSum+=i;
        }
    }
}

void findOdd(ull start,ull end){
    for(ull i=start;i<=end;i++){
        if((i&1)==1){
            OddSum+=i;
        }
    }
}

int main(){


  auto startTime = high_resolution_clock::now();
  ull start=0;
  ull end = 1900000000;


  std::thread t1(findEven,start,end); // thread need callable object which is given as "findEven,start,end";
  std::thread t2(findOdd,start,end);

  t1.join();  // this is to used to join with "main" thread;
  t2.join();

//   findOdd(start, end);
//   findEven(start, end);
  auto StopTime = high_resolution_clock::now();
  auto duration= duration_cast<microseconds>(StopTime-startTime);

  cout<<"OddSum : "<< OddSum<<endl;
  cout<<"EvenSum : "<< EvenSum<<endl;

  cout<<"Sec : "<<duration.count()/1000000<<endl;





    return 0;
}