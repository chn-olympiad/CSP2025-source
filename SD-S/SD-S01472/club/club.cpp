//[HRH]'s Code
#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
const long long Q=998244353;
long long n,m,T,op;
struct ll{
	long long a,b,c;
}q[200020];
vector<ll>v[5];
bool cmp(ll x,ll y){
	long long p=max({x.a,x.b,x.c}),t=x.a+x.b+x.c-p-min({x.a,x.b,x.c});
	long long k=max({y.a,y.b,y.c}),u=y.a+y.b+y.c-k-min({y.a,y.b,y.c});
	return p-t<k-u;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);op=0;
		for(int i=1;i<=3;i++)v[i].clear();
		for(int i=1;i<=n;i++){
			long long a,b,c;
			scanf("%lld%lld%lld",&q[i].a,&q[i].b,&q[i].c);
			long long p=max({q[i].a,q[i].b,q[i].c});
			if(p==q[i].a)v[1].push_back(q[i]);
			else if(p==q[i].b)v[2].push_back(q[i]);
			else v[3].push_back(q[i]);
		}
		for(int i=1;i<=3;i++){
			sort(v[i].begin(),v[i].end(),cmp);
		}
		for(int i=1;i<=3;i++){
			long long k=v[i].size();
			long long p;
			for(int j=0;j<v[i].size();j++){
				if(i==1)p=max(v[i][j].b,v[i][j].c);
				else if(i==2)p=max(v[i][j].a,v[i][j].c);
				else p=max(v[i][j].b,v[i][j].a);
				if(k>n/2)k--,op+=p;
				else{
					if(i==1)op+=v[i][j].a;
					else if(i==2)op+=v[i][j].b;
					else op+=v[i][j].c;
				}
			}
		}printf("%lld\n",op);
	}
	return 0;
}
/**/

