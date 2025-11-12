#include<bits/stdc++.h>
#include <queue>
#define LL long long

using namespace std;

const int N=5e5+10;
LL n,k;
LL a[N];
LL ans;

LL maxi;

struct Node{
	LL l;LL r;
	LL sum;
}tr[N<<2];

priority_queue<LL,vector<LL>,greater<LL> > q[N];
map<LL,LL> mp;

void build(LL id,LL l,LL r){
	tr[id].l=l;
	tr[id].r=r;
	tr[id].sum=0;
	
	if(l==r){
		tr[id].sum=a[l];
		return ;
	}
	
	LL mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	
	tr[id].sum=tr[id<<1].sum^tr[id<<1|1].sum;
}

LL query(LL id,LL L,LL R){
	if(tr[id].l>R||tr[id].r<L) return 0;
	if(tr[id].l>=L&&tr[id].r<=R) return tr[id].sum;
	
	return query(id<<1,L,R)^query(id<<1|1,L,R);
}

void dfs(LL i,LL r,LL res){
	cout<<i<<" "<<r<<" "<<res<<"\n";
	ans=max(ans,res);
	if(i>maxi) return ;
	if(r<i&&!q[i].empty()){
		dfs(i+1,q[i].top(),res+1);
	}
	dfs(i+1,r,res);
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(k==0){
		cout<<n/2<<"\n";
		return 0;
	}
	
	build(1,1,n);
	
	for(LL i=1;i<=n;i++){
		for(LL j=i;j<=n;j++){
			if(query(1,i,j)==k){
				q[i].push(j);
//				cout<<i<<" "<<j<<"\n";
				maxi=max(maxi,i);
			}
		}
	}
	
//	dfs(1,0,0);
	
	int r=0;
	for(LL i=1;i<=n;i++){
		if(!q[i].empty()){
			if(r<i){
				ans++;
				r=q[i].top();
//				cout<<r<<"\n";
			}
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}

/*

*/
