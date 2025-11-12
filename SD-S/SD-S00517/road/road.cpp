#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

struct node{
	int u,v,w;
}a[100005];/*
struct node1{
	int s;
	int c1[100005];
}c[100005];*/
int n,m,k,c[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u >>a[i].v >>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>c[j];
		}
	}
	
		int cnt=0;
		for(int i=1;i<=m;i++){
			cnt+=a[i].w;
		}
		cout<<cnt;
	
	return 0;
}
 
