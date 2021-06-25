// Topic: Types of Thread Creation in C++11.

// there are 5 different type we can create threads in C++11 using callable objects

// NOTE:
//If we  create multiple threads at the same tume it doens't guarantee whihc one will start first




#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std :: chrono;

//1. Function pointer
// this is the very basic form of thred creation

void fun(int x){
    while(x --> 0){
        cout<<x<<endl;
    }
}


int main(){
    std:: thread t1(fun,11);
    t1.join();
    return 0;
}



//2.Lambda Function
//Example:

// int main(){
 
// //other method

// //  auto fun =[](int x){
// //      while(x -->0){
// //          cout<<x<<endl;
// //      }
// //  };

// //  std::thread t(fun, 11);

// //we can directly inject lambda at thread creation time.

//   std::thread t([](int x){
//      while(x -->0){
//          cout<<x<<endl;
//      }
//  }, 11);
//  t.join();
//  return 0;


// }

// 3. Functor (Function Object)

// class Base{

//  public:
//    void operator () (int x){
//        while(x -->0){
//            cout<<x<<endl;
//        }
//    }

// };


// int main(){


//     std::thread t((Base ()),11); // Functor calling 
//     t.join();
//     return 0;
// }


// 4. Non-static member function 

//  class Base{

//      public:
//        void run(int x){
//            while(x-- >0){
//                cout<<x<<endl;
//            }
//        }
//  };

// int main(){
//     Base b;
//     std :: thread t (&Base :: run,&b,11);  // in orde to call non-static member we need object hence, b is used
//     t.join();

//     return 0;
// }


// 5. Static member fuction

// class Base{

//   public:
//     static void run(int x){
//         while(x-- >0){
//             cout<<x<<endl;
//         }
//     }

// };

// int main(){
//     std::thread t(&Base:: run, 11);
//     t.join();
//     return 0;
// }
