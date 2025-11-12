#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}a[1000005];
int q[500005];
long long n,k;
int f[500005];
long long cnt;
int r1;
long long ans=1;
int cmp(node a,node b){
	if(a.r==b.r) return a.l>b.l;
	else return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		f[i]=f[i-1]^q[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((f[j]^f[i-1])==k){
				cnt++;
				a[cnt].l=i;
				a[cnt].r=j;
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	r1=a[1].r;
	for(int i=2;i<=cnt;i++){
		if(a[i].l>=r1+1){
			ans++;
			r1=a[i].r;
		}
	}
	cout<<ans;
	return 0;
}
