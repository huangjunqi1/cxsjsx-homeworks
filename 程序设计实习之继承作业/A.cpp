#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
	char * p;
	public :
		MyString () {p = new char [1];p[0]=0;};
		MyString ( const char * st)
		{
			if (st)
			{
				p = new char [strlen(st)+1];
				strcpy(p,st);
			}
			else p = NULL; 
	 	}
		MyString (const MyString &x)
		{
		//	if (this == &x) return;
			p = new char [strlen(x.p)+1];
			strcpy(p,x.p);
		} 
		~MyString()
		{
			if (p) delete [] p;
		}
		MyString & operator = (const char *x)
		{
			delete [] p;
			p = new char [strlen(x)+1];
			strcpy(p,x);
			return *this;
		}
		MyString & operator = (const MyString & x)
		{
			if (this == &x) return *this; 
			delete [] p;
			p = new char [strlen(x.p)+1];
			strcpy(p,x.p);
			return *this;
		}
		friend MyString operator + (const MyString &x,const MyString &y)
		{
			int len1 = strlen(x.p);
			int len2 = strlen(y.p);
			char *pp = new char[len1+len2+1];
			for (int i=0;i<len1;i++) pp[i]=x.p[i];
			for (int i=0;i<len2;i++) pp[i+len1]=y.p[i];
			return MyString(pp);
		}
		friend MyString operator + (const char * x , const MyString &y)
		{
			int len1 = strlen(x);
			int len2 = strlen(y.p);
			char *pp = new char [len1+len2+1];
			strcpy(pp,x);
			strcpy(pp+len1,y.p); 
			return MyString(pp); 
		}
		friend MyString operator + (const MyString &x , const char * y)
		{
			int len1 = strlen(x.p);
			int len2 = strlen(y);
			char *pp = new char[len1+len2+1];
			for (int i=0;i<len1;i++)
				pp[i]=x.p[i];
			for (int i=0;i<len2;i++)
				pp[i+len1]=y[i];
			return MyString(pp);
		}
		friend ostream & operator << (ostream & os,const MyString & x)
		{
			os << x.p;
			return os; 
		} 
		friend bool operator < (const MyString &x , const MyString &y)
		{
			int len1 = strlen(x.p);
			int len2 = strlen(y.p);
			int len = min(len1,len2);
			for (int i=0;i<len;i++)
			{
				if (x.p[i]!=y.p[i])
					return x.p[i]<y.p[i];
			}
			return len1<len2;
		}
		friend bool operator == (const MyString &x , const MyString &y)
		{
			int len1 = strlen(x.p);
			int len2 = strlen(y.p);
			if (len1!=len2) return 0;
			for (int i=0;i<len1;i++)
				if (x.p[i]!=y.p[i]) return 0;
			return 1;
		} 
		/*operator + (const char *x, const char * y)
		{
			int len1 = strlen(x),len2 = strlen(y);
			
		}*/
		friend bool operator > (const MyString &x,const MyString &y)
		{
			return y<x;
		}
		
		void operator += (const char * st)
		{
			*this = *this + st;
		}
		char & operator [] (int n)
		{ 
			return p[n];
		} 
		char * operator () (int l,int len)
		{
			int r = l+len-1;
			char *pp = new char [r-l+1];
			for (int i=l;i<=r;i++)
				pp [i-l] = p[i];
			return pp;
		}
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}