#include<bits/stdc++.h>
using namespace std;
int n,m,a[21][21],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>a[1][1])
				k++;
		}
	}
	k++;
//	cout<<k<<endl;
	int c=(k-1)/n+1;
	cout<<c<<" ";
	if(c%2==1)
		cout<<(k-1)%n+1;
	if(c%2==0)
		cout<<n-(k-1)%n;
	return 0;
}
/* 
3 3
94 95 96 97 98 99 100 93 92
*/
