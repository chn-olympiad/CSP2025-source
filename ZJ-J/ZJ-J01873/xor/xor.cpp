#include<bits/stdc++.h>

using namespace std;
int f[500005],x[500005];
int p[1005][1005];
int n,k,a[500005],maxn;
bool check(int x){
	int res=0,sum=0;
	for(int i=1;i<=n;i++){
		res^=a[i];
		if(res==k) res=0,sum++;
	}
	if(sum<x) return 0;
	else return 1;
}bool check2(int x){
	int sum=0;
	for(int i=1;i<=n;i++) if(a[i]==k) sum++;
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++){
			f[i]=max(f[i],f[i-1]);
			if((x[i-1]^a[i])==k) x[i]=0,f[i]=max(f[i],f[i-1]+1); 
			else x[i]=x[i-1]^a[i];
		}cout<<f[n];
		return 0;
	}else if(k==0){
		int res=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) res++;
			else if(a[i]==a[i+1]) res++,i++;
		}
		cout<<res;
		return 0;
	}else if(n<=1000){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				for(int k=i;k<=j;k++) p[i][j]^=a[k];
		for(int i=1;i<=n;i++){
			int re=0,u=i;
			for(int j=i;j<=n;j++)
				if(p[u][j]==k) re++,u=j+1;
			maxn=max(maxn,re);
		}
		cout<<maxn;
		return 0;
	}else{
		int l=0,r=n;
		while(l<=r){
			int mid=(l+r)>>1ll;
			if(check(mid)&&check2(mid)) l=mid+1;
			else r=mid-1;
		}cout<<l-1;
		return 0;
	}
	return 0;
}/*
4 0
2 1 0 3

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

6 2
2 3 1 5 0 1


*/
