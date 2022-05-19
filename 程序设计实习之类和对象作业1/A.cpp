#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
	private:
	char Name[100];
	long long Age,ID,s1,s2,s3,s4,ans;
	long long read()
	{
		char ch = getchar();
		long long ans=0;
		while (ch<'0'||ch>'9') ch=getchar();
		while (ch>='0'&&ch<='9')
		{
			ans=ans*10+ch-'0';
			ch=getchar();
		}
		return ans;
	}
	public:
	 	void input()
	 	{
	 		int namelen = 0;
			char ch=getchar();
			while (ch!=',')
			{
				Name[namelen++] = ch; 
				ch=getchar();
			}
			Age = read();
			ID = read();
			s1 = read(), s2 = read() , s3 = read() , s4 = read();
	 	}
	public:
	 	void calculate()
	 	{
	 		ans = s1 + s2 + s3 + s4;
	 	}
	public:
	 	void output()
	 	{
	 		printf("%s,%lld,%lld,",Name,Age,ID);
			if (ans % 4 == 0)
			{
				printf("%lld\n",ans/4);
				return;
			}
			if (ans % 2 == 0)
			{
				printf("%.1f",(double)ans / 4.0);
				return;
			}
			printf("%.2f",(double)ans / 4.0);
	 	}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}