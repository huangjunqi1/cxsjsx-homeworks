#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
		friend istream & operator >> (istream & is , Point & p)
		{
			int a,b;
			is >> a >> b;
			p.x=a,p.y=b;
			return is;
		} 
		friend ostream & operator << (ostream & os , const Point & p)
		{
			os << p.x <<','<< p.y;
			return os;
		}
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}