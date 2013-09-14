浅拷贝并不复制数据，只复制指向数据的指针，因此是多个指针指向同一份数据。 深拷贝会复制原始数据，每个指针指向一份独立的数据。通过下面的代码， 可以清楚地看出它们的区别：

struct Test{
    char *ptr;
};
void shallow_copy(Test &src, Test &dest){
    dest.ptr = src.ptr;
}
void deep_copy(Test &src, Test &dest){
    dest.ptr = (char*)malloc(strlen(src.ptr) + 1);
    memcpy(dest.ptr, src.ptr);
}
浅拷贝在构造和删除对象时容易产生问题，因此使用时要十分小心。如无必要， 尽量不用浅拷贝。当我们要传递复杂结构的信息，而又不想产生另一份数据时， 可以使用浅拷贝，比如引用传参。浅拷贝特别需要注意的就是析构时的问题， 当多个指针指向同一份内存时，删除这些指针将导致多次释放同一内存而出错。

实际情况下是很少使用浅拷贝的，而智能指针是浅拷贝概念的增强。 比如智能指针可以维护一个引用计数来表明指向某块内存的指针数量， 只有当引用计数减至0时，才真正释放内存。

大部分时候，我们用的是深拷贝，特别是当拷贝的结构不大的时候。