#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
	char p[410];
	int lent;
	public: 
	CHugeInt()
	{
		lent = 0;
	}
	CHugeInt (int n)
	{
		int xx = n,cnt=0;
		while (xx) xx/=10,cnt++;
		cnt=0;
		while (n)
		{
			p[cnt++] = n%10+'0';
			n/=10;
		} 
		lent = cnt;
	}
	CHugeInt (char *s)
	{
		int len = strlen(s);	
		for (int i = 0 ; i < len; i++) p[i]=s[len-i-1];
		lent = len;
	}
	CHugeInt (int len,char *s)
	{
		lent = len;
		for (int i=0;i<len;i++) p[i]=s[i];
	}
	~CHugeInt()
	{
		lent = 0;
	}
	CHugeInt & operator = (const CHugeInt & x)
	{
		lent = x.lent;
		for (int i=0;i<lent;i++) p[i]=x.p[i];
		return *this;
	}
	friend CHugeInt operator + (const CHugeInt & x,const CHugeInt & y) 
	{
		int len1 = y.lent;
		int len2 = x.lent;
		int len = max(len1,len2),c=0;
		int tmp[410];
		for (int i = 0;i<len;i++)
		{
			int a,b;
			if (i>=len1) a = 0; else a = y.p[i]-'0';
			if (i>=len2) b = 0; else b = x.p[i]-'0';
			
			tmp[i] = a+b+c;
			c = tmp[i]/10;
			tmp[i]%=10;
		}
		if (c) tmp[len++] = c;
		char *pp;
		pp = new char[len+1]; 
		for (int i=0;i<len;i++) pp[i]=tmp[i]+'0';
		return CHugeInt(len,pp);
	}
	friend CHugeInt operator + (CHugeInt & x,int n)
	{
		int len = x.lent;
		int tmp[410],c=n;
		for (int i=0;i<len;i++)
		{
			tmp[i]=x.p[i]-'0'+c;
			c = tmp[i]/10;
			tmp[i]%=10;
	//		if (!c) break;
		}
		while (c)
			tmp[len++] = c%10,c/=10;
		char *pp;
		pp = new char[len+1]; 
		for (int i=0;i<len;i++) pp[i]=tmp[i]+'0';
		//lent = len;
		return CHugeInt(len,pp);
	}
	friend CHugeInt operator + (int n , const CHugeInt & x)
	{
		int len = x.lent;
		int tmp[410],c=n;
		for (int i=0;i<len;i++)
		{
			tmp[i]=x.p[i]-'0'+c;
			c = tmp[i]/10;
			tmp[i]%=10;
		}
		while (c) tmp[len++] = c%10,c/=10;
		char *pp;
		pp = new char[len+1]; 
		for (int i=0;i<len;i++) pp[i]=tmp[i]+'0';
		return CHugeInt(len,pp);
	}
	friend ostream & operator << (ostream & os , const CHugeInt & x)
	{
		for (int i=x.lent-1;i>=0;i--)
			os << x.p[i];
		return os;
	}
	friend CHugeInt & operator += (CHugeInt & x,int n)
	{
		x = x + n;
		return x;
	}
	friend CHugeInt & operator ++ (CHugeInt & x)
	{
		x = x + 1;
		return x;
	}
	friend CHugeInt operator ++ (CHugeInt & x,int k)
	{
		CHugeInt tmp;
		tmp = x;
		x = x + 1;
		return tmp;
	}
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