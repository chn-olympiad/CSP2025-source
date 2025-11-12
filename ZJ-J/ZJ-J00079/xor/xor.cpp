#include<bits/stdc++.h>
using namespace std;
int n,k,a[10001],t,q[10001];
struct node{
	int l,r,s;
}v[1000001];
struct pm{
	int ml,mr,s;
}dp;
bool cmp(node q,node h){
	if(q.s!=h.s)
		return q.s<h.s;
	if(q.r!=h.r)
		return q.r<h.r;
	return q.l>h.r;
}
int qg(int x,int y){
	if(x==1&&y==1)
		x=0;
	else if(x==0&&y==1)
		x=1;
	return x;
}
int qz(int t,int w){
	int x=a[t];
	for(int i=t+1;i<=w;i++)
		if(x==1&&a[i]==1)
			x=0;
		else if(x==0&&a[i]==1)
			x=1;
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		q[i]=qz(i,i);
		if(q[i]==k){
			v[++t].l=i;
			v[t].r=i;
			v[t].s=1;
		}
		for(int j=i+1;j<=n;j++){
			q[j]=qg(q[j-1],a[j]);
			if(q[j]==k){
				v[++t].l=i;
				v[t].r=j;
				v[t].s=j-i+1;
			}
		}
	}
	dp.ml=n+1;
	dp.mr=0;
	sort(v+1,v+t+1,cmp);
	for(int i=1;i<=t;i++)
		if(dp.ml>v[i].r){
			dp.ml=v[i].l;
			dp.mr=max(dp.mr,v[i].r);
			dp.s++;
		}else if(dp.mr<v[i].l){
			dp.mr=v[i].r;
			dp.ml=min(dp.ml,v[i].l);
			dp.s++;
		}
	cout<<dp.s;
	return 0;
}
