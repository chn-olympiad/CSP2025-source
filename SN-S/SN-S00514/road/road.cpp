//王瑞泽 SN-S00514 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[100100],c[15],cw[10][1005],ans;
pair<int ,int> q[100100];
int main(){
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin>>n>>m>>k;
 	for(int i=1;i<=m;i++)
 	{
 		int x,y;
 		cin>>x>>y;
 		q[i]={x,y};
 		cin>>w[i];
	 }
	 for(int i=1;i<=k;i++)
	 {
	 	cin>>c[i];
	 	for(int j=1;j<=n;j++)
	 	{
	 		cin>>cw[i][j];
		 }
	 }
	 sort(w+1,w+m+1);
	 for(int i=1;i<=n/2;i++)
	 {
	 	ans+=w[i];
	 }
	 cout<<ans;
 	return 0;
} 
