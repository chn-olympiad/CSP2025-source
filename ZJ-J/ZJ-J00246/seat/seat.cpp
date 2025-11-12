#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005],b[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int s=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1;
	bool f=1;
	for(int i=1;i<=n*m;i++)
	{
		b[x][y]=a[i];
		if (f) x++;
		else x--;
		if (x==n+1) x--,y++,f=!f;
		else if (x==0) x++,y++,f=!f;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if (b[i][j]==s)
			{
				cout<<i<<" "<<j;
				break;
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
