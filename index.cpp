#include <iostream>
#include <stdio.h>
//#include "vld.h"
//#include "new.h"
using namespace std;
#include <mutex>
#include <thread>
#include <functional>
std::mutex mutexVar;

class A {
public:
	~A(){
        printf("~A: %d\n", this->num);
    }
	void log(){
		printf("~A log: %d\n", this->num);
	}
   unsigned int num = 1;
    int num1 = 1;

};
class B :public A{
public:
	B(int num){
		this->num = num;
	}
	~B(){
		printf("~B: %d\n",this->num);
	}
};


void threadFunc(){
	mutexVar.lock();
	printf("thread begin\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	printf("thread end\n");
	mutexVar.unlock();
}


class Base{
public:
	mutex               _mutex;
	bool				_run = true;
    thread* _thread = nullptr;
	Base(){
		this->enter();
	}
	~Base(){
		this->exit();
	}
 
	void exit(){
        if (this->_thread) {
            std::unique_lock<std::mutex> lock(_mutex);
            this->_run = false;
            this->_thread->join();
            delete this->_thread;
            this->_thread = nullptr;
        }
	}
	void enter() {
        if (_thread == nullptr) {
            _thread = new thread(doThread, this);
        }
	}
	 
	void loop(){
		while (true) {
			if (!this->_run) {	break; }
		}
	}
	virtual void loopBegin() = 0;
	virtual void loopOver() = 0;
	static void doThread(Base* game){
		game->loopBegin();
		game->loop();
		game->loopOver();  
	}
};
class Game:public Base {
public:
	Game(){
		int a = 1;
	}
	void loopBegin()override{
		int begin = 1;		begin += 100;
	}
	void loopOver()override{
		int over = 10;		over += 10;
	}
};
class AA{
public:
	long long n2 = 2;
	unsigned int n1 = 1;
	int num = 0;
	void change(int n){
		this->num = n;
	}
};
void test(const  AA*  a){
	//a->num = 1;
}
void callback(int a)
{
	printf("%d", a);
}
void main()
{

	//long long a1 = 0/3;

	//AA a;
	//test(&a);
	
	//auto ptr = new Game();
	//ptr->enter();
	//ptr->exit();
	//delete ptr;



    /*B* p=	new B(20);
    printf("before delete: %u\n", p->num);
    delete p;

    printf("after delete: %u\n", p->num);
    printf("max: %u", std::numeric_limits<unsigned int>::max());
    p->log();
    if (p->num == 0xDDDDDDDD){

    int a = 10;
    a++;
    }*/
	//std::thread t(threadFunc);
	//printf("main begin\n");
	//printf("main end\n");
    /*mutexVar.lock();
    mutexVar.unlock();*/
	//t.join();
	//system("pause");
	//A* p1 = new A[2];
	//delete[] p1;

	//char* p = new char[1024*1024];
	//delete p;// why?
}