//SN-J00338 张巍骞 曲江第一中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N =5e3+10;
const int mod = 98244353; 
int n;
int a[N];
struct node{
	int len,maxx,t;
}tr[N];
int asd;
//void add(int k){
//	tr[k].maxx =max(tr[k*2].maxx,tr[k*2+1].maxx);
//}
//void build(int k,int l,int r){
//	tr[k].len =r-l+1;
//	if(l==r){
//		tr[k].maxx = a[l];
//		return;
//	}
//	int mid = (l+r)/2;
//	build(k*2,l,mid);
//	build(k*2+1,mid+1,r);
//	add(k);
//}
//int query(int k,int l,int r,int L,int R){
//	int mass = -1;
//	if(L<=l&&r<=R){
//		mass = max(mass,tr[k].maxx);
//		return mass;
//	}
//	int mid =(l+r)/2;
//	if(L<=mid){
//		mass = max(mass,query(k*2,l,r,L,mid));
//	}
//	if(mid<R){
//		mass = max(mass,query(k*2+1,l,r,mid+1,R));
//	}
//	add(k);
//}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	bool f = false;
	for(int i = 1; i<= n; i++) {
		cin>>a[i];	
		if(a[i]!=1){
			f = true;
		}
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int sum = a[1]+a[2]+a[3];
		int maxx = max(a[1],max(a[2],a[3]));
		if(sum>maxx*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(!f){
		int asd = 1;
		while(n>=3){
			asd=asd*n%mod;
			n--;
		}
		int sdf = (asd/6)%mod;
		cout<<sdf;
		return 0;
	}

	return 0;
}
