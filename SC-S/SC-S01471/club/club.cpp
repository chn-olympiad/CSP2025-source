#include<bits/stdc++.h>
using namespace std;
struct P{
	long long a,b,c,go;
};
P s[100005]={};
long long dfs(int curr,int n,long long cnt1,long long cnt2,long long cnt3,long long a,long long b,long long c){
	long long ans=cnt1+cnt2+cnt3;
	if(curr==n){
		return ans;
	}
	if(a<n/2){
		ans=max(ans,dfs(curr+1,n,cnt1+s[curr].a,cnt2,cnt3,a+1,b,c));
	}
	if(b<n/2){
		ans=max(ans,dfs(curr+1,n,cnt1,cnt2+s[curr].b,cnt3,a,b+1,c));	
	}
	if(c<n/2){
		ans=max(ans,dfs(curr+1,n,cnt1,cnt2,cnt3+s[curr].c,a,b,c+1));	
	}
	return ans;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--){
		int n;
		
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
		}
		cout<<dfs(0,n,0,0,0,0,0,0)<<"\n";
	}
	return 0;
} 