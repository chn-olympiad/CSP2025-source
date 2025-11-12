#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,sum,ca,cb,cc;
struct node{
	int a,b,c,mx,sx;
}a[N];
bool cmp(node x,node y){
	return x.mx-x.sx>y.mx-y.sx;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=ca=cb=cc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].mx=max({a[i].a,a[i].b,a[i].c});
			if(a[i].mx==a[i].a)a[i].sx=max(a[i].b,a[i].c);
			if(a[i].mx==a[i].b)a[i].sx=max(a[i].c,a[i].a);
			if(a[i].mx==a[i].c)a[i].sx=max(a[i].b,a[i].a);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].a==a[i].mx){
				if(ca<n/2){
					ca++;
					sum+=a[i].mx;
				}
				else{
					sum+=a[i].sx;
				}
			}
			else if(a[i].b==a[i].mx){
				if(cb<n/2){
					cb++;
					sum+=a[i].mx;
				}
				else{
					sum+=a[i].sx;
				}
			}
			else if(a[i].c==a[i].mx){
				if(cc<n/2){
					cc++;
					sum+=a[i].mx;
				}
				else{
					sum+=a[i].sx;
				}
			}
		}
		cout<<sum<<'\n';
	}
} 