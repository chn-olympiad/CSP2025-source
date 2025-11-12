#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],pre[500010],r[500010];
int um[2000010];
struct node{
	int l,r;
	bool operator<(const node &x)const{
		return r<x.r;
	}
}q[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=0;i<=(1<<20);i++) um[i]=n+1;
	for(int i=n;i>=0;i--){
		r[i+1]=um[pre[i]^k];
		um[pre[i]]=i;
	}
	for(int i=1;i<=n;i++){
		q[i]={i,r[i]};
	}
	sort(q+1,q+n+1);
	int cnt=0;
	for(int i=1,curr=0;i<=n;i++){
		if(q[i].r>n) continue;
		if(q[i].l>curr){
			cnt++;
			curr=q[i].r;
		}
	}
	cout<<cnt;
	return 0;
}
