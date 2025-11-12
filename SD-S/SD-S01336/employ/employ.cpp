#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[520],wy,vs[520];
string s;
const ll N=998244353;
void sol(int now,int cc,int rs,int sy,int f){
	cout<<now<<" "<<cc<<" "<<rs<<" "<<sy<<"\n";
	if(sy<=0||now>n){
		if(rs>=m)wy++,wy%=N;
		return;
	}
	if(rs+sy<m)return;
	int j=0;
	if(s[now]=='1'){
		for(int i=1;i<=n;i++){
			if(vs[i])continue;
			if(a[i]>=cc){
				j++;
				continue;
			}
			vs[i]=1;
			sol(now+1+j,cc,rs+1,sy-1-j,1);
			vs[i]=0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(vs[i])continue;
			vs[i]=1;
			sol(now+1+j,cc+1,rs,sy-1-j,0);
			vs[i]=0;
		}
	}
}
void sol1(int now){
	if(now==n+1){
		wy++;
		wy%=N;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vs[i]){
			vs[i]=1;
			sol1(now+1);
			vs[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int f=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			f=0;
			break;
		}
	}
	if(f){
		sol1(1);
		printf("%lld\n",wy);
		return 0;
	}
	sol(1,0,0,n,1);
	printf("%lld",wy);
	return 0;
}
//51wyçþÒÃ 
