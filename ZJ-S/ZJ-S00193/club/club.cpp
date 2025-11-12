#include<bits/stdc++.h>
using namespace std;
long long t,n,s1,s2,s3,s;
struct node{
	int fi,se,th;
}a[100005];
bool cmp(node x,node y){
	int xx=max(x.fi,max(x.se,x.th));
	int nx=min(x.fi,min(x.se,x.th));
	int dx=x.fi+x.se+x.th-xx-nx;
	int xy=max(y.fi,max(y.se,y.th));
	int ny=min(y.fi,min(y.se,y.th));
	int dy=y.fi+y.se+y.th-xy-ny;
	if(xx-dx!=xy-dy) return xx-dx>xy-dy;
	if(dx-nx!=dy-ny) return dx-nx>dy-ny;
	if(xx!=xy) return xx>xy;
	if(dx!=dy) return dx>dy;
	return nx>ny;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].fi>>a[i].se>>a[i].th;
		sort(a+1,a+n+1,cmp);
		s1=0;s2=0;s3=0;s=0;
		for(int i=1;i<=n;i++){
			if(a[i].fi>a[i].se&&a[i].fi>a[i].th){
				if(s1+1<=n/2){
					s1++;
					s+=a[i].fi;
				}
				else if(a[i].se>a[i].th){
					s2++;
					s+=a[i].se;
				}
				else{
					s3++;
					s+=a[i].th;
				}
			}
			if(a[i].se>a[i].fi&&a[i].se>a[i].th){
				if(s2+1<=n/2){
					s2++;
					s+=a[i].se;
				}
				else if(a[i].fi>a[i].th){
					s1++;
					s+=a[i].fi;
				}
				else{
					s3++;
					s+=a[i].th;
				}
			}
			if(a[i].th>a[i].fi&&a[i].th>a[i].se){
				if(s3+1<=n/2){
					s3++;
					s+=a[i].th;
				}
				else if(a[i].fi>a[i].se){
					s1++;
					s+=a[i].fi;
				}
				else{
					s2++;
					s+=a[i].se;
				}
			}
		}
		cout<<s<<endl;
	}
}
