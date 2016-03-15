 #include <iostream>
#include <string>  
#include "myList.h" 
  
using namespace std; 
 
template  <class T>  			// 假定顺序表的元素类型为T
class arrList : public List<T>  {		// 顺序表，向量
private:    					// 线性表的取值类型和取值空间
	int  maxSize;            	//私有变量，顺序表实例的最大长度
    int  curLen; 		    		// 私有变量，顺序表实例的当前长度
    int  position;				//私有变量，当前处理位置
   	T  *aList ;            		// 私有变量，存储顺序表的实例
public: 						// 顺序表的运算集
	arrList(const int size) {  		// 创建一个新的顺序表，参数为表实例的最大长度
		maxSize = size; 
		aList = new T[maxSize]; 
		curLen = position = 0; 
	} 
	~arrList() {					// 析构函数，用于消除该表实例
		delete [] aList; 
	}  
	void clear() {      			// 将顺序表存储的内容清除，成为空表
		delete [] aList; 
		curLen = position = 0; 
		aList = new T[maxSize]; 
	} 
    int length(){      			// 返回此顺序表的当前实际长度
        return curLen;
    }
    bool append(T value);			// 在表尾添加一个元素value，表的长度增1
	bool insert(int p, T value);	 	// 在位置p上插入一个元素value，表的长度增1
	bool del(int p); 			//  删除位置p上的元素，表的长度减 1
	int getPos(const T value);		//  在线性表中查找值为value的元素，并返回第1次出现的位置
	void print();                   // 打印线性表
    bool isEmpty(){             // 判断是否为空，若为空则返回真，不为空返回假
        if (curLen==0) {
            return true;
        }else{
            return false;
        }
    }
    T getValue(int p);			 	//  返回位置p的元素值
    T setValue(int p, T value);
};  
 
template <class T>  					// 假定顺序表的元素类型为T
int arrList<T> :: getPos (const T value){
	
	for(int i = 0; i < curLen; i++){
		if(aList[i]==value){
			return i;
		}
	}
	return -1;
} 
 
// 设元素的类型为T， aList是存储顺序表的数组， maxSize是其最大长度；
//  p为新元素value的插入位置,
//插入成功则返回true, 否则返回false
template <class T>  			      		// 假定顺序表的元素类型为T
bool arrList<T> :: insert(int p, const T value){
//	if(curLen==maxSize)
//		resize();//学生注：不清楚其作用...
	if(p>=0&&p<=curLen){
		for(int i = curLen-1; i >= p; i--)
			aList[i+1]=aList[i];
		aList[p] = value;
		curLen++;
		return true;
	}else{
		cout<<"Array index out of range.\n";
		return false;
	}
	
} 

template <class T>  			    // 假定顺序表的元素类型为T
bool arrList<T> :: del(int p){
	if(p<curLen&&p>=0&&curLen>0){
		for(int i = p; i < curLen - 1; i++){
			aList[i] = aList[i+1];
			
		}
		curLen--;
		return true;
	}else{
		cout<<"Array index out of range.\n";
		return false;
	}
}
 
template <class T>  			    //假定顺序表的元素类型为T
void arrList<T> :: print(){ 
	 for (int i = 0; i < curLen; i++) 
        cout << aList[i] << " ";  
     cout << endl;  	 		// 从位置p开始每个元素左移直到curLen,
}
template <class T>
bool arrList<T> :: append(T value){
    aList[curLen] = value;
    curLen++;
    return true;
}
template <class T>
T arrList<T> :: getValue(int p){        //  返回位置p的元素值
    if (p>=0&&p<curLen) {
        return aList[p];
    }else{
        cout<<"Array index out of range.\n";
        return 0;
    }
}
template <class T>
T arrList<T> :: setValue(int p, T value){
    if (p>=0&&p<curLen) {
        aList[p] = value;
        return aList[p];
    }else{
        cout<<"Array index out of range.\n";
        return 0;
    }
}

