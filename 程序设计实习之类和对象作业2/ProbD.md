#### 描述
程序填空，使其输出9 22 5
```cpp
#include <iostream>
using namespace std;
class Sample {
public:
	int v;
// 在此处补充你的代码
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}
```
#### 输入
无
#### 输出
```
9
22
5
```
