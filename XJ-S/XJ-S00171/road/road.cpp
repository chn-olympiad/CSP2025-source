#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[10005][10005],b[20][10005];
struct ab{
	int 
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int xx,yy;
		cin>>xx>>yy;
		cin>>a[xx][yy];
		a[yy][xx]=a[xx][yy];
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	
	return 0;
}
//中华人民共和国万岁 
