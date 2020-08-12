# C++ STL库

## 1. Introduction of Templates

Function template：具有code bloat的side effect，可以不特别指出数据类型，compiler可以根据参数类型选择；

```c++
template <typename T>
T square(T x){
    return x*x;
}

int main(){
    cout<<square<int>(5)<<endl;
    cout<<square<double>(5.5)<<endl;
}
```

Class function：必须给出数据类型

```c++
template<typename T>
class BoVector{
    T arr[1000];
    int size;
  public:
	BoVector():size(0){}
    void push(T x){arr[size]=x;size++;}
    void print() const{
        for(int i=0;i<size;i++){
            cout<<arr[i]<<endl;
        }
    }
}
template<typename T>
//运算符重载
BoVector<T> operator*(const BoVector<T>& rhs1,BoVector<T>&rhs2){
    BoVector<T> ret;
    for(int i=0;i<rhs1.getSize();i++){
        ret.push(rhs1.get(i)*rhs2.get(i));//dot multiply
    }
    return ret;
}

int main(){
    BoVector<int> bv;
    bv.push(2);
    bv.push(5);
    bv.push(8);
    bv.push(9);
    bv.print();
    bv=square(bv);//调用运算符重载函数
}
```

## 2. Introduction of STL: Overview

Standard Template Library：Algorithms & containers & Iterators

```c++
using namespace std;

vector<int> vec;
vec.push_back(4);
vec.push_back(1);
vec.push_back(8);

vector<int>::iterator itr1=vec.begin();	//half-open:[begin,end)
vector<int>::iterator itr2=vec.end();	// behind end

for(vector<int>::iterator itr=itr1;itr!=itr2;++itr){
    cout<<*iter<<" "; // 4 1 8
}
sort(itr1,itr2);//algorithm: vec:{1,4,8}
```

Algorithms do not work on container directly, instead, they work on iterators.

## 3. Introduction of STL: containers 1

- Sequence containers (array and linked list)
  - vector
  - deque
  - list
  - forward list
  - array
- Associative containers(binary tree)
  - set, multiset
  - map, multimap
- Unordered Containers(hash table)
  - Unordered set/multiset
  - Unordered map/multimap

```c++
/*
STL Headers
*/
#include <vector>
#include <deque>
#include <list>
#include <set>				// set and multiset
#include <map>				// map and multimap
#include <unordered_set>	// unordered set/multiset
#include <unordered_map>	// unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric>			// some numeric algorithm
#include <functional>
```

1. Sequence Containers

   1. vector

   ```c++
   vector<int> vec;	//vec.size()==0
   vec.push_back(4);
   vec.push_back(1);
   vec.push_back(8);	//vec:{4,1,8}; vec.size()==3
   
   //索引的两种方法
   cout<<vec[2];		//no range check
   cout<<vec.at(2);	//throw range_error exception if out of range
   for(int i=0;i<vec.size();i++){
       cout<<vec[i]<<" ";
   }
   //这种写法对各种容器都适用
   for(vector<int>::iterator itr=vec.begin();itr!=vec.end();++iter){
       cout<<*itr<<" "//输出数组元素
   }
   for(it:vec)			//C++11
       cout<<it<<" ";
   //vector is a dynamically allocated contiguous array in memory
   int *p=&vec[0];
   p[2]=6;
   ```

   2. deque

   ```c++
   deque<int> deq={4,6,7};
   deq.push_front(2);		//{2,4,6,7},O(1)
   deq.push_back(3);		//{2,4,6,7,3},O(1)
   //insert in the middle:O(n)
   ```

   3. list

   ```c++
   list<int> myist={5,2,9};
   mylist.push_back(6);	//{5,2,9,6}
   mylist.push_front(4);	//{4,5,2,9,6}
   
   list<int>::iterator itr=find(mylist.begin(),mylist.end(),2);	itr->2
   mylist.insert(itr,8);	//{4,5,8,2,9,6},O(1)
   itr++;
   mylist.erase(itr);		//{4,5,8,2,6},	O(1)
   //slower than vector
   // list不使用连续的内存，所以遍历操作特别慢
   // no random access,no [] operator
   ```

   ```c++
   //list的大杀器函数
   mylist1.splice(itr,mylist2,itr_a,itr_b);//O(1)
   //把mylist2从itr_a到itr_b截取出来插到mylist1的itr处
   ```

   4. array

   ```c++
   int a[3]={3,4,5};
   //声明时规定大小
   array<int,3> a={3,4,5};
   a.begin();
   a.end();
   a.size();
   ```

   