#include<bits/stdc++.h>
using namespace std;
long long t,n,a1[100100],sum,ans,a2[100100],a3[100100],vis[100000],maxn,flaga,flagb;
void dfs(long long sum,long long i,long long i1,long long i2,long long i3){
		
	if(i==n+1){
		maxn=max(sum,maxn);
		return ; 
	}
	if(i1<n/2)
	dfs(sum+a1[i],i+1,i1+1,i2,i3);
	if(i2<n/2)
	dfs(sum+a2[i],i+1,i1,i2+1,i3);
	if(i3<n/2)
	dfs(sum+a3[i],i+1,i1,i2,i3+1);
}
struct Node{
	int x,i;
	bool operator<(const Node &a)const{
		return a.x<x;
	}
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			
			if(a2[i]!=0){
				flaga=1;
			}
			if(a3[i]!=0){
				flaga=flagb=1;
			}
		}
		if(n<=10){
			maxn=0;
			dfs(0,1,0,0,0);
			cout<<maxn<<endl;
		}
		else if(flaga==0){
			ans=0;
			sort(a1+1,a1+n+1);
			for(int i=n;i>=n/2;i--){
				ans+=a1[i];
			}
			cout<<ans<<endl;
		}
		else{
			ans=0;
			for(int i=1;i<=n;i++){
			ans+=max(a1[i],max(a2[i],a3[i]));
		}
		cout<<ans<<endl;
			}
		}
return 0;
}
//6 0 5
//5 0 0
//4 0 0
//3 0 0
