#include<bits/stdc++.h>
using namespace std;
long long t,n,q,w,e,s,b[5];
struct node{
	long long x,y,z,k,o,p,q;
}a[100005];
bool cmp(node a,node b){
	if (a.k==b.k) return a.x>b.x;
	return a.k>b.k;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for (int u=1;u<=t;u++){
		cin>>n;s=b[1]=b[2]=b[3]=0;
		for (int i=1;i<=n;i++){
			cin>>q>>w>>e;
			if (q>=w&&q>=e){
				a[i].x=q;a[i].o=1;
				if (w>=e){
					a[i].y=w;a[i].p=2;
					a[i].z=e;a[i].q=3;
				}else{
					a[i].y=e;a[i].p=3;
					a[i].z=w;a[i].q=2;
				}
			}if (w>=q&&w>=e){
				a[i].x=w;a[i].o=2;
				if (q>=e){
					a[i].y=q;a[i].p=1;
					a[i].z=e;a[i].q=3;
				}else{
					a[i].y=e;a[i].p=3;
					a[i].z=q;a[i].q=1;
				}
			}if (e>=q&&e>=w){
				a[i].x=e;a[i].o=3;
				if (q>=w){
					a[i].y=q;a[i].p=1;
					a[i].z=w;a[i].q=2;
				}else{
					a[i].y=w;a[i].p=2;
					a[i].z=q;a[i].q=1;
				}
			}a[i].k=a[i].x-a[i].y;
		}sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++){
			if (b[a[i].o]<n/2){
				b[a[i].o]++;
				s+=a[i].x;
			}else{
				b[a[i].p]++;
				s+=a[i].y;
			}
		}cout<<s<<"\n";
	}
}