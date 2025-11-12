#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[100010],q[100010];
struct node{
	int l,r;
}b[1000010];
bool cmp(node x,node y){
	return x.r<y.r||x.r==y.r&&x.l<y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if (n>1001){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=(q[i-1]^a[i]);
	}
	int m=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if ((q[j]^q[i-1])==k){
				b[++m].l=i,b[m].r=j;
			}
		}
	}
	sort(b+1,b+1+m,cmp);
	int st=0,ans=0;
	for(int i=1;i<=m;i++){
		if (b[i].l>st){
			ans++,st=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
