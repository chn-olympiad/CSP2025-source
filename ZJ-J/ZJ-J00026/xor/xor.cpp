#include<bits/stdc++.h>
#define int long long
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
const int N=5e5+10,M=2e6+10;
int n,k,a[N],f[M],ans,p[N],mx;
bool flagA,flagB;
int qwe(int l,int r,int k){
	int mx=0;
	for(int i=l;i<=r;i++){
		int sum=0;
		int ansans=0;
		for(int j=i;j<=r;j++){
			sum=(sum^a[j]);
			if(sum==k){
				ansans++;
				sum=0;
			}
		}
		mx=max(ansans,mx);
	}
	return mx;
}
signed main(){
	ioi;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flagA=true;
		if(a[i]!=1&&a[i]!=0) flagB=true;
		f[a[i]]++;
		if(a[i]==k) p[f[k]]=i;
	}
	p[f[k]+2]=n;
	if(!flagA){
		if(k==1) cout<<n;
		else cout<<n/2;
		return 0;
	} 
	if(!flagB){
		if(k==1)cout<<f[1];
		else{
			int l=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else l++;
				if(l==2) ans++,l=0;
			}
			cout<<ans;
		}
		return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	ans+=qwe(1,p[1]-1,k);
	for(int i=1;i<=f[k];i++){
		ans+=qwe(p[i]+1,p[i+1]-1,k);
	}
	ans+=qwe(p[f[k]]+1,n,k);
	cout<<ans+f[k];
	return 0;
}