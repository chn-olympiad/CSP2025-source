#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans,l,cnt,m;
ll a[500005],sum[500005],mp[2000005];
struct node{
	int l,r;
}b[500005];
bool cmp(node x,node y){
	if(x.r==y.r){
		return x.l>y.l;
	}
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mp[0]=n+1;
	mp[k]=n+1;
	sum[n+1]=0;
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]^a[i];
		if(mp[k^sum[i]]!=0){
			b[++m].l=i;
			b[m].r=mp[k^sum[i]]-1;
		}
		mp[sum[i]]=i;
//		cout<<sum[i]<<" ";
	}
//	cout<<"\n";
	sort(b+1,b+1+m,cmp);
	int rt=0;
	for(int i=1;i<=m;i++){
//		cout<<b[i].l<<" "<<b[i].r<<"\n";
		if(b[i].l>rt){
			rt=b[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/