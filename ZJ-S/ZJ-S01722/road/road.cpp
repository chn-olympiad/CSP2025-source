#include <bits/stdc++.h>
using namespace std;
int n,m,k,city[1010][1010],con[10][1010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		city[a1][a2]=a3;
		city[a2][a1]=a3;
	}
	for(int i=0;i<k;i++)
	{
		bool flag=1;
		cin>>con[i][0];
		if(con[i][0]!=0) flag=0;
		for(int j=1;j<=n;j++)	cin>>con[i][j];
	}
	cout<<"那还说啥，跳了兄弟-->"<<endl;
	int a[10],*index=a;
	while(1) cout<<index++;
	return 0;
}
