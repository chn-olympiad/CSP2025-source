#include<bits/stdc++.h>
using namespace std;
struct lu{
	int v1,v2;
	int f;
}l[1010];
struct xiang{
	int f;
	int ff[1010];
}x[20];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>l[i].v1>>l[i].v2>>l[i].f;
	}
	for(int i=0;i<k;i++){
		cin>>x[i].f;
		for(int j=0;j<n;j++){
			cin>>x[i].ff[j];
		}
	}
	for(int i=0;i<n;i++){
		if()
	}
	return 0;
}
