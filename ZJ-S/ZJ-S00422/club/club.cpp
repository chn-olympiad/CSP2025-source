#include<bits/stdc++.h>
using namespace std;
struct peop{
	int a,b,c;
}pz[100005];
int T,n,maxn,ans;
bool cmp1(peop x,peop y){
	return x.a>y.a;
}
bool cmp2(peop x,peop y){
	return x.b>y.b;
}
bool cmp3(peop x,peop y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>pz[i].a>>pz[i].b>>pz[i].c;
		}
		maxn=0;
		ans=0;
		sort(pz,pz+n,cmp1);
		for(int i=0;i<n/2;i++)ans+=pz[i].a;
		for(int i=n/2;i<n;i++)ans+=max(pz[i].b,pz[i].c);
		maxn=max(ans,maxn);
		
		ans=0;
		sort(pz,pz+n,cmp2);
		for(int i=0;i<n/2;i++)ans+=pz[i].b;
		for(int i=n/2;i<n;i++)ans+=max(pz[i].a,pz[i].c);
		maxn=max(ans,maxn);
		
		ans=0;
		sort(pz,pz+n,cmp3);
		for(int i=0;i<n/2;i++)ans+=pz[i].c;
		for(int i=n/2;i<n;i++)ans+=max(pz[i].a,pz[i].b);
		maxn=max(ans,maxn);
		
		cout<<maxn<<"\n";
	}
	return 0;
}