#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100005];
int maxxx;
int n;
int b[35][35][35][35];
void dfs(int i,int xa,int xb,int xc,int sum){
	b[i][xa][xb][xc] = max(b[i][xa][xb][xc],sum);
	if(sum<b[i][xa][xb][xc])return;
	if(i==n+1)maxxx = max(maxxx,sum);
	if(i==n+1)return;
	if(xa<n/2)dfs(i+1,xa+1,xb,xc,sum+a[i].a);
	if(xb<n/2)dfs(i+1,xa,xb+1,xc,sum+a[i].b);
	if(xc<n/2)dfs(i+1,xa,xb,xc+1,sum+a[i].c);
	
}
void solve1(){
	memset(b,0,sizeof(b));
	dfs(1,0,0,0,0);
	cout<<maxxx<<endl;
}
bool cm(node x,node y){
	return x.a>x.a;
}
void solve2(){
	sort(a+1,a+n+1,cm);
	int cnt=0;
	for(int i=1;i<=n/2;i++){
		cnt+=a[i].a;
	}
	cout<<cnt<<endl;
}
bool cmp(node x,node y){
	if(abs(x.a-x.b)+abs(x.a-x.c)+abs(x.b-x.c)==abs(y.a-y.b)+abs(y.a-y.c)+abs(y.b-y.c))return abs(x.a-x.b)+abs(x.a-x.c)+abs(x.b-x.c)>abs(y.a-y.b)+abs(y.a-y.c)+abs(y.b-y.c);
	//return max(x.a,max(x.b,x.c))-min(x.a,min(x.b,x.c))>max(y.a,max(y.b,y.c))-min(y.a,min(y.b,y.c));
	
	//return max(max(x.a,x.b),x.c)>max(max(y.a,y.b),y.c);
	return x.a+x.b+x.c<y.a+y.b+y.c;
//	return 
}
void solve4(){
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	int xa=0,xb=0,xc=0;
	int maxx=0;
	
	for(int i=1;i<=n;i++){
		maxx=0;
		int id=0;
		if(xa<n/2){
			maxx = a[i].a;
			id=1;
		}
		if(xb<n/2&&a[i].b>maxx){
			maxx= a[i].b;
			id=2;
		}
		if(xc<n/2&&a[i].c>maxx){
			maxx = a[i].c;
			id=3;
		}
		cnt+=maxx;
		if(id==1)xa++;
		else if(id==2)xb++;
		else xc++;
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		maxxx = 0;
		cin>>n;
		//for(int i=1;i<=n+5;i++)b[i]=0;
		int F=1;
		int FF=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0)F=0;
			if(a[i].c!=0)FF=0;
		}
		if(n<=30)solve1();
		else if(F==1)solve2();
		//else if(FF==1)solve3();
		else solve4();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
