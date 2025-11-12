#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,num = 0;
	cin >> n >> m;
	int s[n],c[n];
	for(int i = 1;i <= n;i++){
		cin >> s[n];
		if(s[n] == 1) num++;
	}
	for(int j = 1;j <= n;j++){
		cin >> c[n];
	}
	
	if(num = n) cout << pow(n,m);
	else cout << 0;
	return 0;
} 
