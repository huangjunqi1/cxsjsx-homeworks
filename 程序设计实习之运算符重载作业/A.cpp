#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
	MyString (const MyString &s)
	{
		p = new char[strlen(s.p)+1];
		strcpy(p,s.p);
	}
	MyString & operator = (const char * s)
	{
		delete [] p;
		p = new char[strlen(s)+1];
		strcpy(p,s);
		return *this;
	}
	MyString & operator = (const MyString & s)
	{
		if (this == &s)	return *this;
		delete [] p;
		p = new char[strlen(s.p)+1];
		strcpy(p,s.p);
		return *this;
	}
	
	friend ostream & operator << (ostream & os,const MyString & s)
	{
		os << s.p;
		return os;
	}
	MyString & Copy(const char *s)
	{
		delete [] p;
		p = new char[strlen(s)+1];
		strcpy(p,s);
		return *this;
	}
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}