#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define RLL register LL
#define PLL pair<LL,LL>
const LL N=1e5+10;
LL a[N][3],n,ans,cnt[3],b[N];

inline void work(){
	ans=cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;
	for(RLL i=1;i<=n;++i){
		RLL mx=0;
		for(RLL j=0;j<3;++j){
			cin>>a[i][j];
			if(a[i][j]>a[i][mx]){
				mx=j;
			}
		}
		ans+=a[i][mx];
		++cnt[mx];
	}
	if((cnt[0]<<1)>n){
		RLL m=0;
		for(RLL i=1;i<=n;++i){
			if(max(a[i][1],a[i][2])-a[i][0]<=0){
				b[++m]=max(a[i][1],a[i][2])-a[i][0];
			}
		}
		sort(b+1,b+m+1);
		while((m<<1)>n){
			ans+=b[m--];
		}
	}else if((cnt[1]<<1)>n){
		RLL m=0;
		for(RLL i=1;i<=n;++i){
			if(max(a[i][0],a[i][2])-a[i][1]<=0){
				b[++m]=max(a[i][0],a[i][2])-a[i][1];
			}
		}
		sort(b+1,b+m+1);
		while((m<<1)>n){
			ans+=b[m--];
		}
	}else{
		RLL m=0;
		for(RLL i=1;i<=n;++i){
			if(max(a[i][0],a[i][1])-a[i][2]<=0){
				b[++m]=max(a[i][0],a[i][1])-a[i][2];
			}
		}
		sort(b+1,b+m+1);
		while((m<<1)>n){
			ans+=b[m--];
		}
	}
	cout<<ans<<'\n';
	return; 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL T;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}
