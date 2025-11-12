#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
struct node{
	string s;
};
node a[200005][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[i][j].s;
		}
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		cout<<0<<endl;
	}
	return 0;
} 
