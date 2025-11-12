#include<bits/stdc++.h>
using namespace std;
int n,k,dp[500005],mx[500005],cnt[2000005],a[500005],yih[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		yih[i]=(yih[i-1]^a[i]);
	}
	for(int i=0;i<=2000000;++i){
		cnt[i]=-1;
	}
	cnt[0]=0;
	for(int i=1;i<=n;++i){
		if(cnt[(k^yih[i])]!=-1){
			dp[i]=mx[cnt[(k^yih[i])]]+1;
		}
		mx[i]=max(mx[i-1],dp[i]);
		cnt[yih[i]]=i;
	}
	cout<<mx[n];
	/*
	我来了，没想到吧。
	我要写：freeopen,.ans,#include<bits\stdc++.h>,#define int long long,FUCK,CCF,NOI,kkksc03,CSP,1145141919810,2147483647
	字数凑到了,bye 
	*/
}
