#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[100000][200000];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<a[1][1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
