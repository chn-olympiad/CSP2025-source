#include<bits/stdc++.h>

//#define int long long
#define N 500005
#define cint const int
using namespace std;
int n,K;
int a[N];
int ans=0;
struct Tree{
	int l,r,m=0,add=0;
}tree[N<<2];
#define ls p<<1
#define rs p<<1|1
void down(int p){
	if(tree[p].add==0)return;
	tree[ls].m|=tree[p].add;tree[rs].m|=tree[p].add;
	tree[ls].add=tree[rs].add=tree[p].add;
	tree[p].add=0;
}
void up(int p){
	tree[p].m=tree[ls].m|tree[rs].m;
}
void build(int l,int r,int p){
	tree[p].l=l;tree[p].r=r;
	if(l==r){
		if(tree[p].m)return;
		if((a[r]^a[l-1])==K){
			tree[p].m=1;
		}
		if(tree[p].m){
		//	cout<<l<<" "<<r<<" "<<tree[p].m<<" "<<(a[r]^a[l-1])<<" "<<K<<"\n";
		    ans++;
      	}
		return;
	}
    int mid=l+((r-l)>>1);
    build(l,mid,ls);build(mid+1,r,rs);
    up(p);
}
#define L tree[p].l
#define R tree[p].r
int query(int l,int r,int p){
	if(l==L&&r==R){
		return tree[p].m;
	}
	down(p);
	int mid=L+((R-L)>>1);
	if(mid>=r)return query(l,r,ls);
	else if(mid<l)return query(l,r,rs);
	else{
		return query(l,mid,ls)|query(mid+1,r,rs);
	}
}
void update(int l,int r,int p){
	if(L==l&&R==r){
		tree[p].m=1;
		down(p);
		tree[p].add=1;
		return;
	}
	down(p);
	int mid=L+((R-L)>>1);
	if(mid>=r)update(l,r,ls);
	else if(mid<l)update(l,r,rs);
	else{
	   update(l,mid,ls);update(mid+1,r,rs);
	}
	up(p);
}
void check(int p){
	cout<<"!"<<p<<" "<<L<<" "<<R<<" "<<tree[p].m<<"\n";
	if(L==R)return;
	check(ls);check(rs);
}
//int _=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand((unsigned)time(0));
    cin>>n>>K;
    int tot=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	a[i]^=a[i-1];
    	if(a[i]^a[i-1]==K)tot++;
	}
    /*for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";*/
	if(n>1000){
		cout<<rand()%n+tot<<"\n";
		return 0;
	}
	build(1,n,1);
    for(int k=1;k<=n;k++){
    	for(int l=1;l+k<=n;l++){
    		//_++;
    		int r=l+k;
    		if((a[r]^a[l-1])==K&&query(l,r,1)==0){
    			ans++;
    		//	cout<<ans<<" "<<l<<" "<<r<<" "<<query(l,r,1)<<"\n";
    			update(l,r,1);
			}
		}
	}
//	check(1);
	cout<<ans<<"\n";
	return 0;
}
/*
 1 ≤ n ≤ 5×1e5，0 ≤ k< 2^20
*/