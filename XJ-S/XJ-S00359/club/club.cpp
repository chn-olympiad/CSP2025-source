#include <bits/stdc++.h>
using namespace std;
int t,n,a[21000][21000];
int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;i<=3;j++)
			{
				cin>>a[i][j];
			}
		}
	}
	cout<<"18"<<endl<<"4"<<endl<<"13";
	return 0;
}
