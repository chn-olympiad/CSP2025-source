#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
}p[N];
int dp[205][205][205],ndp[205][205][205];
bool cmpa(node x,node y){
	return x.a>y.a;
}
bool cmpb(node x,node y){
	return x.b>y.b;
}
bool cmpc(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,i,suma=0,sumb=0,sumc=0,ans=0;
		bool flaga=1;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a>0) suma++;
			if(p[i].b>0) sumb++;
			if(p[i].c>0) sumc++;
		}
		if((!suma&&!sumb)){
			sort(p+1,p+n+1,cmpc);
			for(i=1;i<=n/2;i++) ans+=p[i].c;
			cout<<ans<<"\n";
			continue;
		}
		if((!sumb&&!sumc)){
			sort(p+1,p+n+1,cmpa);
			for(i=1;i<=n/2;i++) ans+=p[i].a;
			cout<<ans<<"\n";
			continue;
		}
		if((!suma&&!sumc)){
			sort(p+1,p+n+1,cmpb);
			for(i=1;i<=n/2;i++) ans+=p[i].b;
			cout<<ans<<"\n";
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			for(suma=0;suma<=n/2;suma++){
				for(sumb=0;sumb<=n/2;sumb++){
					sumc=i-suma-sumb;
					if(sumc<0||sumc>n/2) continue;
					int tmp1=0,tmp2=0,tmp3=0;
					if(suma) tmp1=dp[suma-1][sumb][sumc]+p[i].a;
					if(sumb) tmp2=dp[suma][sumb-1][sumc]+p[i].b;
					if(sumc) tmp3=dp[suma][sumb][sumc-1]+p[i].c;
					ndp[suma][sumb][sumc]=max(tmp1,max(tmp2,tmp3));
					if(i==n) ans=max(ans,ndp[suma][sumb][sumc]);
				}
			}
			for(suma=0;suma<=n/2;suma++){
				for(sumb=0;sumb<=n/2;sumb++){
					sumc=i-suma-sumb;
					if(sumc<0||sumc>n/2) continue;
					dp[suma][sumb][sumc]=ndp[suma][sumb][sumc];
					ndp[suma][sumb][sumc]=0;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}