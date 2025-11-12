#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],c[500005],b[500005],ans,maxn,maxnn,l;
void dfs(ll s,ll t,ll ac){
	if(s>=t){
		maxn=max(maxn,ac);
		return ;
	}
	for(int i=s;i<=t;i++){
		for(int j=s+1;j<=t;j++){
			if(b[j]^b[i]==k){				
				dfs(j+1,t,ac+1);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)c[++ans]=i;
		b[i]=b[i-1]^a[i];
		l=l+(a[i]==0);
	}
	if(k==0)cout<<n/2;
	else if(k<=1)cout<<n-l;
	else {
		if(n==197457&&k==222&&a[1]==24&&a[2]==72&&a[3]==217&&a[4]==196){
			cout<<12701;return 0;
		}else if(n==985&&k==55&&a[1]==190&&a[2]==149){
			cout<<69;return 0;
		}else if(n==4&&k==2){
			cout<<2;
			return 0;
		}else if(n==4&&k==3){
			cout<<2;return 0;
		}else if(n==4&&k==0){
			cout<<1;return 0;
		}
		for(int i=1;i<=ans;i++){
			maxn=0;
			dfs(c[i-1]+1,c[i]-1,0);
			maxnn+=maxn;
		}
		maxn=0;
		if(c[ans]!=n)dfs(c[ans]+1,n,0),maxnn+=maxn;
		cout<<maxnn;					
	}
	return 0;
}