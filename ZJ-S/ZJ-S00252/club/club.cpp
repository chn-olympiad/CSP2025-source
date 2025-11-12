#include<bits/stdc++.h>
using namespace std;
int t,n,m,mx,mn,ans,ac,bc,cc;
struct node{
	int a,b,c,d,mx,e;
}a[200001];
bool cmp(node a,node b){
	return a.e>b.e;
}
signed main(){
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t--;){
		cin>>n;
		ans=ac=bc=cc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			mx=max(a[i].a,max(a[i].b,a[i].c));
			mn=min(a[i].a,min(a[i].b,a[i].c));
			if(a[i].a!=mx&&a[i].a!=mn){
				a[i].d=a[i].a;
			}
			else if(a[i].b!=mx&&a[i].b!=mn){
				a[i].d=a[i].b;
			}
			else a[i].d=a[i].c;
			a[i].mx=mx;
			a[i].e=a[i].mx-a[i].d;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			//cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<" "<<a[i].d<<" "<<a[i].mx<<"\n";
			if(a[i].a==a[i].mx){
				if(ac==n/2){
					ans+=a[i].d;
				}
				else{
					ans+=a[i].a;
					ac++;
				}
			}
			else if(a[i].b==a[i].mx){
				if(bc==n/2){
					ans+=a[i].d;
				}
				else{
					ans+=a[i].b;
					bc++;
				}
			}
			else{
				if(cc==n/2){
					ans+=a[i].d;
				}
				else{
					ans+=a[i].c;
					cc++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
