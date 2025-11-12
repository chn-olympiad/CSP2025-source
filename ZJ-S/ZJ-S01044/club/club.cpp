#include<bits/stdc++.h>
using namespace std;
long long t;
struct node{
	long long x,y,z,ok;
	long long fmx,smx;
}a[100005];
bool cmp(node x,node y){
	return x.fmx>y.fmx;
}
bool cmp1(node x,node y){
	if(x.ok==y.ok) return x.fmx-x.smx<y.fmx-y.smx;
	return x.ok<y.ok;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			long long b[3]={a[i].x,a[i].y,a[i].z};
			sort(b,b+3);
			a[i].fmx=b[2];
			a[i].smx=b[1];
		}
		sort(a+1,a+1+n,cmp);
		long long q=0,w=0,e=0,sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i].fmx;
			if(a[i].x==a[i].fmx) q++,a[i].ok=1;
			else if(a[i].y==a[i].fmx) w++,a[i].ok=2;
			else e++,a[i].ok=3;
		}
		if(q>n/2){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(q==n/2) break;
				if(a[i].ok==1){
					q--;
					sum+=a[i].smx-a[i].fmx;
				}
			}
		}
		else if(w>n/2){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(w==n/2) break;
				if(a[i].ok==2){
					w--;
					sum+=a[i].smx-a[i].fmx;
				}
			}
		}
		else if(e>n/2){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(e==n/2) break;
				if(a[i].ok==3){
					e--;
					sum+=a[i].smx-a[i].fmx;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
