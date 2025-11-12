#include<bits/stdc++.h>
using namespace std;

struct node{
	int c;
	int v;
	int b;
}a[100005];
bool judge(node a[],int numm){
	for(int i=1;i<=numm;i++){
		if(a[i].v!=0&&a[i].b!=0){
			return 0;
		}
	}
	return 1;
}
int f(node a[]){
	int maxx=a[1].c+a[2].v;
	if(a[1].v+a[2].c>maxx){
		maxx=a[1].v+a[2].c;
	}
	if(a[1].b+a[2].c>maxx){
		maxx=a[1].b+a[2].c;
	}
	if(a[1].c+a[2].b>maxx){
		maxx=a[1].c+a[2].c;
	}
	if(a[1].v+a[2].b>maxx){
		maxx=a[1].v+a[2].b;
	}
	if(a[1].b+a[2].c>maxx){
		maxx=a[1].b+a[2].c;
	}
	return maxx;
}
bool cmt(node a,node b){
	return a.c>b.c;
}
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n=0;
		long long ans=0;
		a[100005]={};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c>>a[i].v>>a[i].b;
		}
		if(judge(a,n)==1){
			sort(a+1,a+n+1,cmt);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].c;
			}
		}
		if(n==2){
			ans=f(a);
		}
		cout<<ans<<endl;
	}
	return 0;
}