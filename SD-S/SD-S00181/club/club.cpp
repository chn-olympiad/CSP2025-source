#include<bits/stdc++.h>
#define int long long 
using namespace std;
int T;
struct node{
	int a,b,c,maxx,cmax,cha;
}a[100005];
bool cmp(node a,node b){
	return a.cha>b.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		int n,ans=0,x=0,y=0,z=0;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].maxx=max({a[i].a,a[i].b,a[i].c});
			if(a[i].maxx==a[i].a) a[i].cmax=max(a[i].b,a[i].c);
			if(a[i].maxx==a[i].b) a[i].cmax=max(a[i].a,a[i].c);
			if(a[i].maxx==a[i].c) a[i].cmax=max(a[i].a,a[i].b);
			a[i].cha=a[i].maxx-a[i].cmax;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].maxx==a[i].a){
				if(x<n/2){
					ans+=a[i].a;
					++x;
				}
				else ans+=a[i].cmax;
			}
			else if(a[i].maxx==a[i].b){
				if(y<n/2){
					ans+=a[i].b;
					++y;
				}
				else ans+=a[i].cmax;
			}
			else{
				if(z<n/2){
					ans+=a[i].c;
					++z;
				}
				else ans+=a[i].cmax;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
