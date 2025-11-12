#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using LL=long long;
using VI=vector<int>;
int n,m;
string s;
vector<int> pers;
const int MOD=998244353;
int used[20];
LL fac[20];
void __init__(){
	fac[0]=1;
	FOR(i,1,20)fac[i]=fac[i-1]*i%MOD;
}
void dfs(int l,int cnt,LL& ans){
	if((l-1-cnt)>=m)return (ans+=fac[n-l+1])%=MOD,void();
	if(l==n+1)return;
	FOR(i,0,n){
		if(used[i])continue;
		used[i]=1;
		if(s[l-1]=='0'||pers[i]<=cnt)dfs(l+1,cnt+1,ans);
		else dfs(l+1,cnt,ans);
		used[i]=0;
	}
}
void solve1(){
	/*vector<int> id(n);
	FOR(i,0,n)id[i]=i;
	int ans=0;
	do{
		int cnt=0,failcnt=0;
		FOR(i,0,n){
			int ii=id[i];
			if(s[i]=='0')failcnt++;
			else if(pers[ii]<=failcnt)failcnt++;
			else cnt++;
		}
		if(cnt>=m)ans++;
	}while(next_permutation(begin(id),end(id)));
	cout<<ans;*/
	__init__();
	LL ans=0;
	dfs(1,0,ans);
	cout<<ans;
}
void solve2(){
	FOR(i,0,n)if(s[i]=='0')return cout<<0,void();
	FOR(i,0,n)if(pers[i]==0)return cout<<0,void();
	LL ans=1;
	REP(i,1,n)ans=ans*i%MOD;
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	pers.resize(n);
	FOR(i,0,n)cin>>pers[i];
	if(n<=18)solve1();//8~20pts
	else if(m==n)solve2();//4pts
	return 0;
}
