/*
Sample Input 
5 4
93 100 98 97 96 99 92 91 95 94 89 90 88 86 87 81 83 84 82 85
Sample Output
2 3
*/
#include<bits/stdc++.h>
using namespace std;
int a[150],b[15][15],n,m,r;
int main()
{
//  考试结束后，必须去除注释! 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)  cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m/2;i++)  swap(a[i],a[n*m-i+1]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i%2==1)  b[j][i]=a[(i-1)*m+j];
			else  b[m-j+1][i]=a[(i-1)*m+j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		if(b[i][j]==r)  cout<<j<<" "<<i;
	}
	return 0;
}

