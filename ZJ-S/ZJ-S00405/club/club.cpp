#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+100;
ll T,n,f1,f2,f3;
ll b[N];
struct node {
	int x,y,z;
}a[N];
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;
		f1=f2=f3=0;
		ll k=0;
		ll s=0;
		for (int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int t=max(a[i].x,max(a[i].y,a[i].z));
			if (t==a[i].x)f1++,s+=a[i].x;
				else if (t==a[i].y) f2++,s+=a[i].y;
					else f3++,s+=a[i].z;
			
		}
		if (f1>n/2){
			for (int i=1;i<=n;i++){
				int t=max(a[i].x,max(a[i].y,a[i].z));
				if (t==a[i].x) b[++k]=a[i].x-max(a[i].z,a[i].y);
			}
			sort(b+1,b+1+k);
			for (int i=1;i<=f1-n/2;i++)s-=b[i];
		}
		if (f2>n/2){
			for (int i=1;i<=n;i++){
				int t=max(a[i].x,max(a[i].y,a[i].z));
				if (t==a[i].y) b[++k]=a[i].y-max(a[i].z,a[i].x);
			}
			sort(b+1,b+1+k);
			for (int i=1;i<=f2-n/2;i++)s-=b[i];
		}
		if (f3>n/2){
			for (int i=1;i<=n;i++){
				int t=max(a[i].x,max(a[i].y,a[i].z));
				if (t==a[i].z) b[++k]=a[i].z-max(a[i].y,a[i].x);
			}
			sort(b+1,b+1+k);
			for (int i=1;i<=f3-n/2;i++)s-=b[i];
		}
		cout<<s<<endl;
	}
}
