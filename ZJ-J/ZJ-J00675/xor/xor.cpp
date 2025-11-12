#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N],lst[5000005],gg,ans=0;
struct node{
	int l,r;
}b[N];
inline bool cmp(node x,node y){
	return x.r<y.r||(x.r==y.r&&x.l>y.l);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=n;i>=0;i--){
		if(lst[k^sum[i-1]]){
			b[i].r=lst[k^sum[i-1]];
		}else b[i].r=0x3f3f3f3f;
		if(a[i]==k) b[i].r=i;
		b[i].l=i;
		lst[sum[i]]=i;
//		cout<<i<<' '<<b[i].l<<' '<<b[i].r<<'\n';
	}
	sort(b,b+n+1,cmp);
	gg=-1;
	for(int i=0;i<=n;i++){
		if(b[i].r==0) continue;
		if(b[i].r==0x3f3f3f3f) break;
		if(b[i].l>gg){
			ans++;
			gg=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
