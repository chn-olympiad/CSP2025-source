#include<bits/stdc++.h>
using namespace std;
int n,m;
int s;
int c[505],y[505],z[505],c1[505],x[505];
int summary = 1;
int main(){
	freopen("employ1.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++) cin>>c[i];
	for(int i = 1;i<=n;i++){
		y[i] = s%10;
		s/=10;
	}
	for(int i = 1;i<=n;i++){
		if(y[i] == 0 || c[i] == 0){
			continue;
		}
		z[i] = y[i];
		c1[i] = c[i];
	}
	sort(c1+1,c1+n+1);
	for(int i = 1;i<=n;i++){
		if(c1[i] == 0){
			continue;
		}
		else{
			int e = 1;
			if(e * c1[i] != 0){
				x[i] = c1[i];
			}
		}
	}
	
	for(int i = 1;i<=n;i++){
		int lin = 1;
		if(x[i] == x[i-1]) lin++;
		else{
			summary *= lin;
			lin = 1;	
		}
	}
	cout<<summary%998244353;
	return 0;
}
