#include <bits/stdc++.h>
using namespace std;
struct s{
	int b,c,d;
}a[100001];
int t,n,x,y,z,q,w,p,h,l;
long long ans;
bool cmp(s k,s h){
	if(k.d!=l&&h.d==l) return 0;
	if(k.d==l&&h.d!=l) return 1;
	if(k.d!=l&&h.d!=l) return 1;
	if(k.b-k.c==h.b-h.c) return 1;
	return k.b-k.c<h.b-h.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		x=0;
		y=0;
		ans=0;
		z=0;
		for(int i=1;i<=n;i++){
			cin>>q>>w>>p;
			a[i].b=max({q,w,p});
			if(q>=w&&q<=p) a[i].c=q;
			if(q>=p&&q<=w) a[i].c=q;
			if(w>=p&&w<=q) a[i].c=w;
			if(w>=q&&w<=p) a[i].c=w;
			if(p>=w&&p<=q) a[i].c=p;
			if(p>=q&&p<=w) a[i].c=p;
			if(a[i].b==q){
				x++;
				a[i].d=1;
			}else if(a[i].b==w){
				y++;
				a[i].d=2;
			}else{
				z++;
				a[i].d=3;
			}
		}
		if(x>n/2){
			h=x-n/2;
			l=1;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=h;i++){
				a[i].b=a[i].c;
			}
		}else if(y>n/2){
			h=y-n/2;
			l=2;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=h;i++){
				a[i].b=a[i].c;
			}
		}else if(z>n/2){
			h=z-n/2;
			l=3;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=h;i++){
				a[i].b=a[i].c;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].b;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//std::ios::sync_with_stdio(false);
//cin.tie(0);
//cout.tie(0);
  
