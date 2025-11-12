#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+1e2;
//const int N=1e4+1e2;
int a[N],f[N];
int n,k,ans;
//struct node{
//int l,r;
//}ans[N];

//struct node{
//int ls,rs,x;
//}tree[N];

//void build(int l,int r,int p){
//	int mid=(l+r)>>1;
//	if(l==r){
//		tree[p].ls=l;
//		tree[p].rs=r;
//		tree[p].x=a[l];
//		return;
//	}
//	build(l,mid,p<<1);
//	build(mid+1,r,p<<1|1);
//	tree[p].ls=l;
//	tree[p].rs=r;
//	tree[p].x=(tree[p<<1].x^tree[p<<1|1].x);
//	return;
//}

//int work(int l,int r){
// 	if(l==r) return f[l][r]=a[l];
// 	if(f[l][r]) return f[l][r];
//	else{
//     	int mid=(l+r)>>1;
//		f[l][r]=work(l,mid)^work(mid+1,r);
//	}
//}
//int query(int l,int r,int p){
//	if(tree[p].rs<l) return 0;
//	if(tree[p].ls>r) return 0;
//	if(tree[p].ls>=l&&tree[p].rs<=r) return tree[p].x;
//	if(tree[p].ls==tree[p].rs) return 0;
//	int ls=p<<1;
//	int rs=p<<1|1;
//	return query(l,r,ls)^query(l,r,rs);
//}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k<=1&&n>1000){
		for(int i=2;i<=n;i++){
			if(a[i-1]==k) ans++;
			else if((a[i]^a[i-1])==k) ans++,i++;
		}
		cout<<ans;
	}
//	build(1,n,1);
//	for(int i=1;i<=n*2;i++){
//		cout<<tree[i].ls<<" "<<tree[i].rs<<" "<<tree[i].x<<"\n";
//	}
//	work(1,n);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
//	}
	for(int i=1;i<=n;i++){
		int q=a[i];
		if(q==k) f[i]=max(f[i-1]+1,f[i]);
		for(int j=i+1;j<=n;j++){
			q^=a[j];
			f[j]=max(f[j],f[j-1]);
			if(q==k) f[j]=max(f[i-1]+1,f[j]);
		}
		ans=max(ans,f[i]);
	}
//	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	cout<<ans;
	return 0;
}
