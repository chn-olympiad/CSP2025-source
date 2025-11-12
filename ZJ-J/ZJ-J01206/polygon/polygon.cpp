#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
int n,a[N],ans,maxx;
vector<int> f,ff;
inline void dfs(int x,int s){
	if(s>a[x]*2){
		ans++;
		if(ans==mod)ans=0;
	}
	if(x==n)return;
	for(int i=x+1;i<=n;i++)
		dfs(i,s+a[i]);
} 
inline void solve1(){
	dfs(0,0);
	printf("%d",ans);
	return;
}
inline void solve2(){
	f.resize(maxx+2);ff.resize(maxx+2);
	f[0]=1;int nm=0;
	for(int i=1;i<=n;++i){
		nm+=a[i];
		if(i>=3){
			for(int j=a[i]+1;j<=nm;++j)
				(ans+=f[j])%=mod; 
		}
		for(int j=0;j<=nm;++j)
			ff[j]=f[j];
		for(int j=a[i];j<=nm;++j)
			(f[j]+=ff[j-a[i]])%=mod; 
	}
	printf("%d",ans);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),maxx+=a[i];
	sort(a+1,a+n+1);
	if(n<=20)
		solve1();
	else solve2();
	return 0;
} 
