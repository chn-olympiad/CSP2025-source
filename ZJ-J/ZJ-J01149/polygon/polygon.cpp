#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],f[5005],mod=998244353,ans;
vector<int>x;
int check(vector<int>p){
	int maxn=-1,tot=0;
	for(int i=0;i<p.size();i++){
		tot+=p[i];maxn=max(maxn,p[i]);
	}return (tot>maxn*2);
}
void dfs(int last,int num,vector<int>p){
	if(num>=3&&check(p)){
		ans++;ans%=mod;
	}for(int i=last+1;i<=n;i++){
		p.push_back(a[i]);
		dfs(i,num+1,p);
		p[p.size()-1]=0;
	}
}
int main(){
	//t4!!! i know it's dp! but my math too cai so that i can't solve
	//55555555555 so difficult!!!
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);int tp=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);if(a[i]!=1)tp=1;
	}if(tp==0){
		for(int i=3;i<=n;i++){
			int ii=min(i,n-i),ans1=1;
			for(int j=n;j>=n-ii+1;j--)ans1*=j,ans1%=mod;
			for(int j=ii;j>=2;j--)ans1/=j,ans1%=mod;
			ans+=ans1;
		}printf("%d",ans);return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0,x);printf("%d",ans);
	return 0;
}

