#include<bits/stdc++.h>
using namespace std;
struct node{
	int n,t,c;
};
node a[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,aa[11][10005];
	long long l=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].n>>a[i].t>>a[i].c;
		l+=a[i].c;
	}
	for(int i=1;i<=k;i++){
		cin>>aa[i][0];
		for(int j=1;j<=n;j++){
			cin>>aa[i][j];
		}
	}
	cout<<l;
	return 0;
}

