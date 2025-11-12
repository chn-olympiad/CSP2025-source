#include<bits/stdc++.h>
using namespace std;
int sum,lena,lenb,lenc;
struct node{
	int a,b,c;
}g[100005];
bool cmp(node x,node y){
	int maxx=max({x.a,x.b,x.c}),maxy=max({y.a,y.b,y.c}),nmaxx,nmaxy;
	if(maxx==x.a) nmaxx=max(x.c,x.b);
	else if(maxx==x.b) nmaxx=max(x.c,x.a);
	else nmaxx=max(x.a,x.b);
	if(maxy==y.a) nmaxy=max(y.c,y.b);
	else if(maxy==y.b) nmaxy=max(y.c,y.a);
	else nmaxy=max(y.a,y.b);
	return maxx-nmaxx>maxy-nmaxy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		sum=0,lena=0,lenb=0,lenc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>g[i].a>>g[i].b>>g[i].c;
		sort(g+1,g+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<g[i].a<<" "<<g[i].b<<" "<<g[i].c<<"\n";}
		for(int i=1;i<=n;i++){
			int maxx=max({g[i].a,g[i].b,g[i].c});
			if(maxx==g[i].a){
				int nmaxx=max(g[i].b,g[i].c);
				if(lena==n/2){
					if(nmaxx==g[i].b) lenb++,sum+=g[i].b;
					else lenc++,sum+=g[i].c;}
				else lena++,sum+=g[i].a;}
			else if(maxx==g[i].b){
				int nmaxx=max(g[i].a,g[i].c);
				if(lenb==n/2){
					if(nmaxx==g[i].a) lena++,sum+=g[i].a;
					else lenc++,sum+=g[i].c;}
				else lenb++,sum+=g[i].b;}
			else{
				int nmaxx=max(g[i].b,g[i].a);
				if(lenc==n/2){
					if(nmaxx==g[i].b) lenb++,sum+=g[i].b;
					else lena++,sum+=g[i].a;}
				else lenc++,sum+=g[i].c;}}
		cout<<sum<<"\n";}
	return 0;
} 