#include<bits/stdc++.h>
#define int long long
#define N 1000010
using namespace std;
int n,i,ansb,a[N];const int mod=998244353;
void sc(int t,int ma,int ans,int b){
	if(t==n+1){
		if(b>=3&&ans>ma*2)ansb++;
		if(ansb>=mod)ansb-=mod;
		return;
	}
	sc(t+1,max(ma,a[t]),ans+a[t],b+1);
	sc(t+1,ma,ans,b);
}//O(n^2)
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sc(1,0,0,0);cout<<ansb;
	return 0;
}
//9:42 guoleyangli1--3 yuji40pts
//9:43 100+100+40~60+40=280~300pts,wanjiesahua!(doge)
//10:52 100+100+60+40=300pts(bu zhi dao wen bu wen)
//RP++
//zzh749903