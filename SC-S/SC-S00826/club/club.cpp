#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll T,n,nx,ny,nz,mx,x[N],y[N],z[N];
bool f=1;
struct nod{
	ll a,b,c,abc;
}a[N];
bool cmp(ll i,ll j){
	return a[i].abc<a[j].abc;
}
bool cmpp(nod a,nod b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b||a[i].c) f=0;
			ll ax=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a==ax){
				a[i].abc=ax-max(a[i].b,a[i].c);
				x[++nx]=a[i].abc;
			}else if(a[i].b==ax){
				a[i].abc=ax-max(a[i].a,a[i].c);
				y[++ny]=a[i].abc;
			}else{
				a[i].abc=ax-max(a[i].a,a[i].b);
				z[++nz]=a[i].abc;
			}
			mx+=ax;
		}
		if(f){
			mx=0;
			sort(a+1,a+1+n,cmpp);
			for(int i=1;i<=(n/2);i++){
				mx+=a[i].a;
			}
			cout<<mx<<"\n";
			continue;
		}
		if(nx>(n/2)){
			sort(x+1,x+1+nx);
			for(ll i=1;i<=nx-n/2;i++){
				mx-=x[i];
			}
		}else if(ny>(n/2)){
			sort(y+1,y+1+ny);
			for(ll i=1;i<=ny-n/2;i++){
				mx-=y[i];
			}
		}else if(nz>n/2){
			sort(z+1,z+1+nz);
			for(ll i=1;i<=nz-n/2;i++){
				mx-=z[i];
		//	cout<<a[i].abc<<" ";
			}
		}
		cout<<mx<<"\n";
		nx=0,ny=0,nz=0,mx=0;
	}
}