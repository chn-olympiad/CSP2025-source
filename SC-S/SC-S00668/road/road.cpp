#include<bits/stdc++.h>
using namespace std;
struct mm{
	int u,v,w;
};
int cn(mm a,mm b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	map<int,int>z;
	int n,m,k,cnt=0,sum=0,flag=1;
	cin>>n>>m>>k;
	mm a[10000];
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		if(c!=0)flag=0;
		for(int j=1;j<=n;j++){
		int d;
		cin>>d;
		if(d!=0)flag=0; 
		}
	}
	if(flag==1){
	cout<<0;
	return 0;	
	}
	
	sort(a+1,a+1+m,cn);
	for(int i=1;i<=m;i++){
		if(cnt==n)
		if(z[a[i].u]!=1)cnt++;
		if(z[a[i].v]!=1)cnt++;
			sum+=a[i].w;
			z[a[i].u]=1;
			z[a[i].v]=1;
	}
	cout<<sum;
	
	return 0;

} 
