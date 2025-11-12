#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x=0,cnt=0,y,f;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(j>=1){
				x=0;
				y=j;
				f=j;
				while(y--){
					x+=a[f]|a[f-1];
					f--;	
				}
				if(x==m){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
