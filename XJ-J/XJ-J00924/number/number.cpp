#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n,a[1000005],t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> (s+1);
	n = strlen(s+1);
	for(int i = 1;i <= n;i++){
		if(isdigit(s[i])){
			a[++t] = s[i]-'0';
		}
	}
	sort(a+1,a+t+1,greater<int>());
	for(int i = 1;i <= t;i++){
		cout << a[i];
	}
	return 0;
} 
