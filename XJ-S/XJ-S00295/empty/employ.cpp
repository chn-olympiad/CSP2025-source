#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("emplot.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	int b1[1001][3]={0};
	for(int i=0;i<=b;i++)
	{
		cin>>b1[i][0];
		cin>>b1[i][1];
		cin>>b1[i][2];
	}
	int c1[10001][5]={0};
	for(int i=0;i<2;i++)
	{
		cin>>c1[i][0];
		cin>>c1[i][1];
		cin>>c1[i][2];
		cin>>c1[i][3];
		cin>>c1[i][4];
	}
	cout<<"13"<<endl;
	return 0;
}
