#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,T;
long long ans,cnta,cntb,cntc;
struct node{
	long long a;
	long long b;
	long long c;
}f[N];
bool cmp(node x,node y){
	return max({x.a,x.b,x.c})>=max({y.a,y.b,y.c});
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>f[i].a>>f[i].b>>f[i].c;
		}
		sort(f+1,f+1+n,cmp);
		for(int i=1;i<=n;++i){
			if(f[i].a>=max(f[i].b,f[i].c) && cnta<(n/2)){
				ans+=f[i].a;
				cnta++;
			}
			else if(f[i].b>=max(f[i].a,f[i].c) && cntb<(n/2)){
				ans+=f[i].b;
				cntb++;
			}
			else if(f[i].c>=max(f[i].b,f[i].a) && cntc<(n/2)){
				ans+=f[i].c;
				cntc++;
			}else {
				if((f[i].a>=f[i].b && cnta<(n/2)) || cntb==(n/2)){
					ans+=f[i].a;
					cnta++;
				}
				else {
					ans+=f[i].b;
					cntb++;
				}		
			}
		}
		cout<<ans<<"\n";
		ans=0,cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;++i)f[i].a=0,f[i].b=0,f[i].c=0;
	}
	return 0;
}

