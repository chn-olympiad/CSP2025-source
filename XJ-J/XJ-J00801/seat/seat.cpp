#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]>a[0][0])cnt++;
	double l=ceil((cnt+1)/n+1);
	int hang;
	cout<<l<<' ';
	int lie=int(l); 
	if(lie%2!=0){
		hang=(cnt+1)%n;
		if(hang==0)hang=n;
	}	
	if(lie%2==0)hang=n-(cnt+1)%n+1;
	cout<<hang;
}
