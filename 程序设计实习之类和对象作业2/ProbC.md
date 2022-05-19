#### 描述
程序填空，输出指定结果
```cpp
#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	int k;
	Base(int n):k(n) { }
};
class Big
{
public:
	int v;
	Base b;
// 在此处补充你的代码
};
int main()
{
	int n;
	while(cin >>n) {
		Big a1(n);
		Big a2 = a1;
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
}
```
#### 输入
多组数据，每组一行，是一个整数
#### 输出
对每组数据，输出两行，每行把输入的整数打印两遍
#### 样例输入
```
3
4
```
#### 样例输出
```
3,3
3,3
4,4
4,4
```	