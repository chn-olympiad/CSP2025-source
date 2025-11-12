//汤佳忆  SN-S00442  西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+5;
int t,a,b,c,maxn=-INT_MAX;
struct f {
	int a,b,id;
} s[100001],ss[100001],sss[100001],ssss[100001];
bool cmp(f a,f b) {
	return a.a>b.a;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1; i<=t; i++) {
		int n;
		cin>>n;
		bool bb=false,cc=false;
		for(int j=1; j<=n; j++) {
			cin>>s[j].a>>ss[j].a>>sss[j].a;
			if(ss[j].a!=0)bb=!bb;
			if(sss[j].a!=0) cc=!cc;
		}
		if(bb==false&&cc==false) {
			sort(s+1,s+1+n,cmp);
			int sum=0;
			for(int j=1; j<=n/2; j++) {
				sum+=s[j].a;
			}
			cout<<sum<<"\n";
			return 0;
		}
		if(bb=true) {
			
			int sum=0;
			for(int j=1; j<=n; j++) {
				ssss[j].a=s[j].a;
				ssss[j].b=ss[j].a;
			}
			sort(ssss+1,ssss+1+n,cmp);
			for(int j=1;j<=n/2;j++){
				sum+=ssss[j].a;
			}
			for(int j=(n/2)+1;j<=n;j++){
				sum+=ssss[j].b;
			}
			cout<<sum<<"\n";
			return 0;
		}

	}
	return 0;
}
