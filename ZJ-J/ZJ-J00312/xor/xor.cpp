#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int b[500005];
struct node{
	int l,r;
} z[10000005];
int o=1;
bool cmp(node x,node y){
	if(x.r==y.r){
		return x.l>y.l;
	}else{
		return x.r<y.r;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]^b[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<": "<<b[i]<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				z[o].l=i;
				z[o].r=j;
				o++;
			}
		}
	}o--;
//	for(int i=1;i<=o;i++){
//		cout<<i<<": "<<z[i].l<<" "<<z[i].r<<endl;
//	}
//	cout<<o<<endl;
	sort(z+1,z+1+o,cmp);
	int nx=0;
	int cnt=0;
	for(int i=1;i<=o;i++){
		if(z[i].l>nx){
			nx=z[i].r;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
