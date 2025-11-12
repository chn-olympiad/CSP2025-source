#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=500000+5;
const int inf=2147483647;
//
ll a[MAXN],s[MAXN],dp[MAXN];
int n,t,ans=-inf;
ll k;
bool one;
//
int dfs(int l,int r){	
	if(l==r){
		if(a[l]==k){
			return 1;
		}
	}else if(l<r){
		if(s[r]^s[l-1]==k){
			for(int i=l;i<r;++i){
				t=dfs(l,i)+dfs(i+1,r);
				if(t>ans)ans=t;
				return t;
			}	
			return 1;
		}	
		for(int i=l;i<r;++i){
			t=dfs(l,i)+dfs(i+1,r);
			if(t>ans)ans=t;
			return t;
		}
		return ans;
	}
	
}
//
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(i==1){
			s[1]=a[1];
		}else {
			s[i]=s[i-1]^a[i];
		}
		if(a[i]!=1)one=1;
	}
	if(k==0){
		printf("%d",n/2);
		return 0;
	}else if(one==0){
		if(k==0){
			printf("%d",n/2);
			return 0;
		}else {
			printf("%d",n);
			return 0;
		}
	}else{
		/*for(int i=1;i<=n;++i){
			printf("%d ",s[i]);
		}*/
		printf("%d",dfs(1,n));
	}
/*
4 0 
2 1 0 3

5 1
1 0 1 0 1
*/
	return 0;
}