#include<bits/stdc++.h>
using namespace std;
int u[1000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin >> a;
	for(int i = 1;i <= a;i ++){
		cin >> u[i];
	}
	if(a < 3) cout << 0;
	else{
		if(max(u[1],max(u[2],u[3])) * 2 < u[1] + u[2] + u[3]) cout << 1;
		else cout << 0;
	}
	return 0;
}
