#include <iostream>
using namespace std;

int bitManipulation3(int n, int i) {
return ((~ (n >> ( 32 - i ))) << (32 - i)) + (n & ( ( ( 1LL << (32-i) ) - 1 )));
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}