#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct p{
	int a,b,c;
}a[100005];
bool cmp1(p x,p y){
	return x.a>y.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		int ans=0;
		int v=n/2;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=v;i++){
			ans+=a[i].a;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
