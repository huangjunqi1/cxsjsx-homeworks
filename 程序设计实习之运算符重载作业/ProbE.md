#### 描述
程序填空，输出指定结果
```cpp
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
```
#### 输入
多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
#### 输出
对每组数据，输出6行，内容分别是：
#### 样例输入
```
99999999999999999999999999888888888888888812345678901234567789 12
6 6
```
#### 样例输出
```
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14
```