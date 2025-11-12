#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	cin >> n;
	char a[1000005] = n;
	sort(a + n + 1,a + 1);
	for(int i = 1;i <= a.size;i++){
		cout << a[i] << endl;
	}
	return 0;
}
