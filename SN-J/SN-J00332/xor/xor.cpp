#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,k,a[MAXN],xr[MAXN],flag[MAXN],cnt;
struct node{
	int l,r;
};
vector<node> e,q;
bool cmp(node x,node y){
	return (x.l!=y.l?x.l<y.l:x.r>y.r);
}
bool cmp1(node x,node y){
	return (x.r!=y.r?x.r<y.r:x.l>y.l);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		xr[i]=xr[i-1]^a[i];
	}
	int maxl=0;
	for(int r=1;r<=n;r++){
		for(int l=r;l>=1;l--){
			if(l<=maxl) break;
			if((xr[r]^xr[l-1])==k){
				q.push_back((node){l,r});
				break;
			}
		}
	}
	if(q.size()==0){
		cout<<"0\n";
		return 0;
	}
	int cnt=1,lst=0;
	for(int i=0;i<q.size();i++){
		if(i&&q[i].l>q[lst].r) cnt++,lst=i;	
	}
	cout<<cnt;
	return 0;
}
