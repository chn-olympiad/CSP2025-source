#include<bits/stdc++.h>
using namespace std;
int n,t,cluba,clubb,clubc,ans;
struct NODE{
	int a;
	int b;
	int c;
	bool f;
}x[100005];
bool cmpa(NODE x,NODE y){
	return x.a>y.a;
}
bool cmpb(NODE x,NODE y){
	return x.b>y.b;
} 
bool cmpc(NODE x,NODE y){
	return x.c>y.c;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int c=n/2;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].f=0;
		}
		sort(x+1,x+n+1,cmpa);
		for(int i=1;i<=c;i++){
			if(x[i].f==0){
				ans+=x[i].a;
				x[i].f=1;
				cluba++;
			}
		}
		sort(x+1,x+n+1,cmpb);
		for(int i=1;i<=c;i++){
			if(x[i].f==0){
				ans+=x[i].b;
				x[i].f=1;
				clubb++;
			}
		}
		sort(x+1,x+n+1,cmpc);
		for(int i=1;i<=c;i++){
			if(x[i].f==0){
				ans+=x[i].c;
				x[i].f=1;
				clubc++;
			}
		}
		cout<<ans<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<x[i].a<<"="<<x[i].b<<"="<<x[i].c<<"+"<<x[i].f<<endl;
//		}
		cluba=0,clubb=0,clubc=0,ans=0;
	}
	return 0;
}
