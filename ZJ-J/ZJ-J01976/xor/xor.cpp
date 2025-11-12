#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	int l,r,sum=0;
}tree[4*N];
int a[N],dp[N];
int mmax(int aa,int bb){
	if(aa>bb)return aa;
	return bb;
}
void build(int p,int l,int r){
	tree[p].l=l,tree[p].r=r;
	if(l==r){
		tree[p].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p].sum=tree[p<<1].sum^tree[p<<1|1].sum;
}
int ask1(int p,int l,int r){
	if(l<=tree[p].l && tree[p].r<=r){
		return tree[p].sum;
	}
	int mid=(tree[p].l+tree[p].r)/2,ans=0;
	if(l<=mid)ans^=ask1(p<<1,l,r);
	if(r>mid)ans^=ask1(p<<1|1,l,r);
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;	
	}
	if(f==0 && k==0){
		if(n==1){
			cout<<1;
		}else{
			cout<<n/2;
		}
		return 0;
	}else{
		build(1,1,n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i<=j && ask1(1,i,j)==k){
					dp[j]=dp[i-1]+1; 
				}
			}
		}
		cout<<dp[n];
	}
	return 0;
}

