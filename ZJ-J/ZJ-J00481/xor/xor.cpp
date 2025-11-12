#include<bits/stdc++.h>
using namespace std;
#define lll long long
int n,m;
struct node1{
	int ll;
	int rr;
	int s;
}tr[2000010];
int k;
int ans=1;
int s;
struct node{
	int x,y;
}qj[2000010];
int a[500010];
bool cmp(node s1,node s2){
	return s1.y<s2.y;
}
void build(int k,int l,int r){
	tr[k].ll=l;
	tr[k].rr=r;
	if(l==r){
		tr[k].s=a[l];
//		cout<<k<<" "<<tr[k]<<endl;
		return;
	}
	int mid=(l+r)/2;
	if(mid>=l) build(k*2,l,mid);
	if(mid<r) build(k*2+1,mid+1,r);
	tr[k].s=tr[k*2].s^tr[k*2+1].s;
//	cout<<k<<" "<<tr[k]<<endl;
}
int cx(int k,int l,int r){
	int lx=tr[k].ll;
	int rx=tr[k].rr;
//	s++;
//	if(s>=30) return 0;
	if(l<=lx&&rx<=r){
		return tr[k].s;
	}
	int mid=(lx+rx)/2;
	int ans1=-1;
	int ans2=-1;
	if(mid>=l) ans1=cx(k*2,l,r);
	if(mid<r) ans2=cx(k*2+1,l,r);
	if(ans1==-1){
		return ans2;
	}
	if(ans2==-1){
		return ans1;
	}
	return ans1^ans2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
//	cout<<"1111111111111"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
//			cout<<i<<"  "<<j<<"  "<<cx(1,i,j)<<endl; 
			if(cx(1,i,j)==m){
				qj[++k].x=i;
				qj[k].y=j;
			}
//			cout<<"111111111111"<<endl;
		}
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	sort(qj+1,qj+1+k,cmp);
//	for(int i=1;i<=k;i++) cout<<qj[i].x<<" "<<qj[i].y<<endl;
	int s1=qj[1].y;
	for(int i=2;i<=k;i++){
		int s2=qj[i].x;
		if(s2>s1){
			ans++;
			s1=qj[i].y;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 0
2 1 0 3
*/
