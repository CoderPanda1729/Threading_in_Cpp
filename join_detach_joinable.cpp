// join Notes

// 0. Once a threst started we wait for this thread to finish by calling join() function to thread object.

//1. Double join will result inot program termination

// 3. If needed we should check thread is joinable before joining. (using joinable() function)

//DETACH NOTES:

// 0. This is used to detach newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and
//  double detach() will result into program termination.

// 2. If we have detached thread and main funtion is returing then the detach thread execution is suspended.

/// Notes:
// Either join() or detach() should be called on thred object , otherwise during thread object's destruction it will
// terminate the program. Because inside destructor it checks if thread is still joinable ? If yes then it terminated the program.

#include<iostream> 
#include<chrono>
#include<thread>
using namespace std;


void run (int count){
    while(count-- >0)
       cout<< count <<" CPPNuts"<<endl;
    std::this_thread::sleep_for(chrono :: seconds(5)); // this will do delay for this thread for 3 sec 
    cout<<" Thread finished"<<endl;
}


int main(){

    std::thread t1(run,10);
    cout<<"main()" <<endl;
    //t1.join();
    // t1.join();  // two times join is not allowed , as that thread is already completed and you have already waited in upper 

    // to avoid this check it again if you can use join again or not 
    // if(t1.joinable()){
    //     t1.join();
    // }

    t1.detach(); // this will detach t1 form main thread ,and due to this we cannot able to print data of run function , because before it complete it execution "main" thread
    //is alredy return (see command return 0). To resolve this  you can write wait function before return 0;
    cout<<"main() after"<<endl;
    return 0;
}