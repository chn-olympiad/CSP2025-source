#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	string s,int count = 0;
	int a[10] = {};
	cin << s;
	for(i = 1;i <= 5;i++){
		if (s[i].isdigit()){
			a[count] = s[i];
			count ++;
		}
	}
	for(i = 1;i <= 5;i++){
		cout << a[i];
	}
	return 0;
}
