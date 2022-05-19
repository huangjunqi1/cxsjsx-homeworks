#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
	int ** a;
	int col,row;
	public:
		Array2 () 
		{
			col = 0,row = 0;
			a = new int * [1];
			a[0] = new int [1];
			a[0][0]=0;
		}
		Array2 (int n,int m) : col(n),row(m)
		{
			if (!n && !m) a = NULL;
			else
			{
				a = new int * [n+1];
				for (int i = 0; i < n ;i++)
					a[i] = new int [row+1];
			 } 
		}
		Array2 & operator = (const Array2 & xx)
		{
			if (this == &xx) return *this;
			if (a) delete [] a;
			col = xx.col;
			row = xx.row;
			a = new int * [col+1];
			for (int i=0;i<col;i++)
				 a[i] = new int [row+1];
			memcpy(a,xx.a,sizeof(int)*(col+1)*(row+1));
			return *this;
		}
		~Array2()
		{
			if (a) delete [] a;
		} 
		int * operator [] (int i)
		{
			return a[i];
		}
		int & operator () (int x,int y)
		{
			return a[x][y];
		}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}