#include<bits/stdc++.h>
#define int long long
using namespace std;
struct mem{int h1,h2,h3;}a[1000010];
int T,n,co[1000010],os[1000010];
int r1,r2,r3,sum,f1,f2,f3;
bool cmp1(mem x,mem y){return x.h1>y.h1;}
bool cmp2(mem x,mem y){
	if(x.h1<=y.h1) return x.h2>y.h2;
	return x.h1>y.h1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		r1=0,r2=0,r3=0,sum=0,f1=1,f2=1,f3=1;
		memset(co,0,sizeof(co));
		memset(os,0,sizeof(os));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].h1>>a[i].h2>>a[i].h3;
			if(a[i].h2!=0) f1=0;
			if(a[i].h3!=0) f2=0;
		}
		if(f1==1&&f2==1){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++) sum+=a[i].h1;
			cout<<sum<<"\n";
		}
		else if(f2==1){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++) sum+=a[i].h2;
			for(int i=n/2+1;i<=n;i++) sum+=a[i].h1;
			cout<<sum<<"\n";
		}
	}
	return 0;
}