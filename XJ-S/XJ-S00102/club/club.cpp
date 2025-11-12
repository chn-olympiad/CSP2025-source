#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100010];
long long t,n,ans;
bool cmpa(node x,node y){
	return x.a>=y.a&&x.b>=y.b&&x.c>=y.c;
}
int main(){
	ios_base::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		ans=0;
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+1+n,cmpa);
		int cnta=0,cntb=0,cntc=0;
		for (int i=1;i<=n;i++){
			int x=a[i].a,y=a[i].b,z=a[i].c;
			int q=max({x,y,z});
			if (q==a[i].a){
				if (cnta<n/2){
					ans+=a[i].a;
					cnta++;
				}
				else{
					int d=max(a[i].b,a[i].c);
					if (d==a[i].b&&cntb<n/2){
						ans+=a[i].b;
						cntb++;
					}
					else{
						ans+=a[i].c;
						cntc++;
					}
				}
			}
			else if (q==a[i].b){
				if (cntb<n/2){
					ans+=a[i].b;
					cntb++;
				}
				else{
					int d=max(a[i].a,a[i].c);
					if (d==a[i].a&&cnta<n/2){
						ans+=a[i].a;
						cnta++;
					}
					else{
						ans+=a[i].c;
						cntc++;
					}
				}
			}
			else{
				if (cntc<n/2){
					ans+=a[i].c;
					cntc++;
				}
				else{
					int d=max(a[i].a,a[i].b);
					if (d==a[i].a&&cnta<n/2){
						ans+=a[i].a;
						cnta++;
					}
					else{
						ans+=a[i].b;
						cntb++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 