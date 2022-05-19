#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }

	Complex()
	{
		r = i = 0;
	}
	Complex(char *s)
	{
		int len = strlen(s),pos;
		for (int ii = 0;ii<len;ii++)
		{
			if (s[ii] == '+')
			{
				pos = ii;
				break;
			} 
		}
		r = i = 0;
		for (int ii = 0; ii < pos ; ii ++)
			r = r*10+s[ii]-'0';
		for (int ii=pos+1;ii<len-1;ii++)
			i = i*10+s[ii]-'0';
	} 

};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}