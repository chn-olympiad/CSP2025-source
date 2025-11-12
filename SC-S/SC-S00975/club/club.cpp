#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll Max;
struct node{
	ll a,b,c;	
}s[100100];
void dfs(ll num,ll qid,ll wid,ll eid,ll sum){
	if(eid>n/2||wid>n/2||qid>n/2){
		return ;
	}
	if(num==n+1){
		if(Max<sum){
			Max=sum;
		}
		return ;
	}
	dfs(num+1,qid+1,wid,eid,sum+s[num].a);
	dfs(num+1,qid,wid+1,eid,sum+s[num].b);
	dfs(num+1,qid,wid,eid+1,sum+s[num].c);
	return ;
}
int main(){
	ll k;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&k);
	while(k--){
		scanf("%lld",&n);
		Max=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c); 
		}	
		dfs(0,0,0,0,0);
		printf("%lld\n",Max);	
	}
	return 0;
}
