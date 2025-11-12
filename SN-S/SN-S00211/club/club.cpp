#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int maxn=1e5+10;
const int inf=1e18;
int t;
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		int a[maxn];
		int b[maxn];
		cin>>n;
		int sum=0;
		int maxx=-inf;
		int f=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i]=x;
			b[i]=y;
			maxx=max(x,y);
			sum+=maxx;
			if(b!=0){
				f=1;
			}
		}
		int ans=0;
		if(!f){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<"\n";
		}
		else{
			cout<<maxx<<"\n";
		}
	}
	return 0;
}
