#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>m;
	cout<<n<<m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x=0,cnt=0,y,f;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
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
	cout<<cnt;
	return 0;
}
