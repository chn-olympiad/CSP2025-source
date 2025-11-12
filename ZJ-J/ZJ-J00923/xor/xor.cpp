#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f[500005],t=0,ans=1,v,u=0;
struct node{
	int l,r;
}x[500005];
bool cmp(node x,node y){
	return x.r<y.r;
	if(x.r==y.r)return x.l>y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1]=a[1];f[0]=0;
	for(int i=2;i<=n;i++)f[i]=f[i-1]^a[i];
	for(int i=1;i<=n;i++){
		if(t!=0)u=x[t].r;
		for(int j=u;j<i;j++)
		if((f[i]^f[j])==k)t++,x[t].l=j+1,x[t].r=i;
	}
	sort(x+1,x+t+1,cmp);
	v=x[1].r;
	for(int i=2;i<=t;i++)
	if(x[i].l>v)ans++,v=x[i].r;
	cout<<ans;
	return 0;
}
