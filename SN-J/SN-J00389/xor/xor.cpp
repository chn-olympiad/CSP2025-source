//SN-J00389  张爱熙  西安高新第一中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
unsigned ll k,n,a[N],ans,p,sum[N];
struct node{
	ll l,r;
	bool operator<(const node &x)const{
		if(x.r==r) return x.l>l;
		else return x.r<r;
	}
};
priority_queue<node> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		sum[i]=a[i];
		if(a[i]==k) q.push({i,i});
		for(ll j=i+1;j<=n;j++){
			sum[j]=sum[j-1]^a[j];
			if(sum[j]==k) q.push({i,j});
		}
	}
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		if(tmp.l<=p) continue;
		ans++;
		p=tmp.r;
	}
	cout<<ans;
	return 0;
}
