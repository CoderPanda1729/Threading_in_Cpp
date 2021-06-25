// TOPIC: Mutex in C++ Threading |Why Use Mutex | What is Race Condition And How to solve it ? | What is critical Section

// Mutex : Mutual Exclusion

// RACE CONDITION:
// 0.; Race condition is a situation where two or more threads /process happend to change a common  data at the same time.
// 1. if there is a race condition then we have to protect it and the protected section is called critical section/region.

// MUTEX :
// 0.Mutex is used to avoid race condition.
// 1. We us lock() ,unlock() on mutex to avoid race condition

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int myAmount=0;
std:: mutex m;

void addMoney(){

    m.lock();
    ++myAmount;
    m.unlock();
}


int main(){
    std:: thread t1(addMoney);
    std:: thread t2(addMoney);
    std:: thread t3(addMoney);

    t1.join();
    t2.join();
    t3.join();

    cout<<myAmount<<endl;

    return 0;
}