// C++中名字隐藏是什么.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

让我们通过一个例子来讲解C++中的名字隐藏。在C++中，如果一个类里有一个重载的方法， 你用另一个类去继承它并重写(覆盖)那个方法。你必须重写所有的重载方法， 否则未被重写的方法会因为名字相同而被隐藏，从而使它在派生类中不可见。

请看例子：

class FirstClass{
public:
    virtual void MethodA(int);
    virtual void MethodA(int, int);
};
void FirstClass::MethodA(int i){
    cout<<"ONE"<<endl;
}
void FirstClass::MethodA(int i, int j){
    cout<<"TWO"<<endl;
}
上面的类中有两个方法(重载的方法)，如果你想在派生类中重写一个参数的函数， 你可以这么做：

class SecondClass : public FirstClass{
public:
    void MethodA(int);
};
void SecondClass::MethodA(int i){
    cout<<"THREE"<<endl;
}

int main (){
    SecondClass a;
    a.MethodA(1);
    a.MethodA(1, 1);
    return 0;
}
上面的main函数中，第2个MethodA在编译时会报错，提示没有与之匹配的函数。 这是因为两个参数的MethodA在派生类中是不可见的，这就是名字隐藏。

名字隐藏与虚函数无关。所以不管基类中那两个函数是不是虚函数， 在这里都会发生名字隐藏。解决方法有两个。第一个是将2个参数的MethodA换一个名字， 那么它在派生类中就可见了。但我们既然重载了MethodA，说明它们只是参数不同， 而实际上应该是在做相同或是相似的事的。所以换掉名字并不是个好办法。因此， 我们一般采用第二种方法，在派生类中重写所有的重载函数。