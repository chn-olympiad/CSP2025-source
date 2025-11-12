#include<bits/stdc++.h>
using namespace std;
int t,n,a[101010],b[101010],c[101010];
struct node{
	int shu,id,idd;
}h[303030];
int cmp(node a,node b){
	return a.shu>b.shu;
}
int main(){
	freopen("club.cpp","r".stdin);
	freopen("club.cpp","w".stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a1=0,b1=0,c1=0,sum=0,vis[101010];
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			h[(j-1)*3+1].shu=a[j];
			h[(j-1)*3+2].shu=b[j];
			h[(j-1)*3+3].shu=c[j];
			h[(j-1)*3+1].id=1;
			h[(j-1)*3+2].id=2;
			h[(j-1)*3+3].id=3;
			h[(j-1)*3+1].idd=j;
			h[(j-1)*3+2].idd=j;
			h[(j-1)*3+3].idd=j;
		}
		sort(h+1,h+3*n+1,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=h[i].shu;
		}
		cout<<sum<<endl;
	}
	return 0;
}
