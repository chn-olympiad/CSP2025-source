#include <bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k;
int a[N];
struct point{
	int l,r,k;
}f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		if (a[i]==k){
			f[i].k=1;
		}
		else{
			f[i].l=f[i].r=a[i];
		}
	}
	for (int i=2;i<=n;i++){
		int now=(f[i-1].r^f[i].l);
		if (now==k){
			now=1;
		}
		else{
			now=0;
		}
		f[i].k=f[i-1].k+f[i].k+now;
		f[i].l=f[i-1].l;
		if (a[i]==0){
			f[i].r=f[i-1].r;
		}
		else{
			f[i].r=f[i].r;
		}
	}
	cout<<f[n].k<<endl;
	return 0;
}
