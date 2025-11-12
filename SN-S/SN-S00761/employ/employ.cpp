#include<bits/stdc++.h>

using namespace std;
int u[10000000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long r=1;
	cin >> n>>m;
	string h;
	cin >> h;
	for(int i=0;i<n;i++) cin >> u[i];
	int q=0;
	for(int i=0;i<n;i++){
		if(u[i]==0) q++;
	}
	n-=q;
	for(int i=n;i>0;i--){
		r*=i;
	}
	cout << r%998244353;
	return 0;
}
