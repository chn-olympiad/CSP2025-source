#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int T,n;
struct node{
	int a,b,c;
	int fc,sc,fi,si,ti,fd,sd,td;
}a[N];
bool cmp(node a,node b){
	if(a.fc!=b.fc)
		return a.fc>b.fc;
	else 
		return a.sc>b.sc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		int np[10];
		memset(np,0,sizeof(np));
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].fi=a[i].a;
				if(a[i].b>=a[i].c){
					a[i].si=a[i].b;
					a[i].ti=a[i].c;
					a[i].fd=1;
					a[i].sd=2;
					a[i].td=3;
				}
				else{
					a[i].si=a[i].c;
					a[i].ti=a[i].b;
					a[i].fd=1;
					a[i].sd=3;
					a[i].td=2;
				}
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				a[i].fi=a[i].b;
				if(a[i].a>=a[i].c){
					a[i].si=a[i].a;
					a[i].ti=a[i].c;
					a[i].fd=2;
					a[i].sd=1;
					a[i].td=3;
				}
				else{
					a[i].si=a[i].c;
					a[i].ti=a[i].a;
					a[i].fd=2;
					a[i].sd=3;
					a[i].td=1;
				}
			}
			else if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				a[i].fi=a[i].c;
				if(a[i].a>=a[i].b){
					a[i].si=a[i].a;
					a[i].ti=a[i].b;
					a[i].fd=3;
					a[i].sd=1;
					a[i].td=2;
				}
				else{
					a[i].si=a[i].b;
					a[i].ti=a[i].a;
					a[i].fd=3;
					a[i].sd=2;
					a[i].td=1;
				}
			}
			else {
				a[i].fi=a[i].a;
				a[i].si=a[i].b;
				a[i].ti=a[i].c;
				a[i].fd=1;
				a[i].sd=2;
				a[i].td=3;
			}
			a[i].fc=a[i].fi-a[i].si;
			a[i].sc=a[i].si-a[i].ti;
		}
		sort(a+1,a+1+n,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			int tf=a[i].fd,ts=a[i].sd,tt=a[i].td;
			if(np[tf]<n/2){
				np[tf]++;
				ans+=a[i].fi;
			}
			else if(np[ts]<n/2){
				np[ts]++;
				ans+=a[i].si;
			}
			else{
				np[tt]++;
				ans+=a[i].ti;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

