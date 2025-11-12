#include<bits/stdc++.h>
using namespace std;
int n,k,s[500010],a[500010],c[500010],t,f[500010];
struct node{
	int pos,val;
}b[500010];
bool cmp(node a,node b){
	if(a.val!=b.val) return a.val<b.val;
	return a.pos>b.pos;
}
int fin(int x,int y){
	int l=0,r=n,s=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(b[mid].val>x) r=mid-1,s=mid;
		else if(b[mid].val<x) l=mid+1;
		else if(b[mid].pos<y) s=mid,r=mid-1;
		else l=mid+1;
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		b[i].val=s[i];
		b[i].pos=i;
		c[i]=-1;
	}
	sort(b,b+1+n,cmp);
	for(int i=1;i<=n;i++){
		t=fin(k^s[i],i);
		if(t!=-1&&b[t].val==(k^s[i])&&b[t].pos<i) c[i]=b[t].pos;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(c[i]!=-1) f[i]=max(f[i],f[c[i]]+1);
	}
	cout<<f[n]<<endl;
	return 0;
}
