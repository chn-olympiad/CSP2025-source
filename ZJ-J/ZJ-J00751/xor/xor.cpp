#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int lst=0,cnt=0;
int m=0;
struct node{
	int l,r;	
}b[N];
struct Node{
	int l,r;
	long long sum;
}tr[N*4];
bool cmp(node x,node y){
	return x.r<y.r;
}
long long query_Xor(int l,int r){
	long long s=a[l];
	for(int i=l+1;i<=r;i++)s=s^a[i];
	return s;
}
void pushup(int u){
	tr[u].sum=tr[u<<1].sum^tr[u<<1|1].sum;
}
void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r;
	if(l==r){
		tr[u].sum=a[l];
		return;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	pushup(u);
}
long long query(int u,int l,int r){
	if(l<=tr[u].l&&tr[u].r<=r)return tr[u].sum;
	int mid=tr[u].l+tr[u].r>>1;
	int ans=0;
	if(l<=mid)ans=query(u<<1,l,r);
	if(r>mid)ans^=query(u<<1|1,l,r);
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=100){
		for(int i=1;i<=n;i++){
			int l=i,r=i;
			while(r<=n){
				int ans=query_Xor(l,r);
				if(ans==k){
					++m;
					b[m]={l,r};
					break;
				}
				r++;
			}
		}
		sort(b+1,b+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(b[i].l>lst){
				lst=b[i].r;
				cnt++;
			}
		}
		cout<<cnt;
	}
	else{
		build(1,1,n);
		for(int i=1;i<=n;i++){
			int l=i,r=i;
			while(r<=n){
				int ans=query(1,l,r);
				if(ans==k){
					++m;
					b[m]={l,r};
					break;
				}
				r++;
			}
		}
		sort(b+1,b+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(b[i].l>lst){
				lst=b[i].r;
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}