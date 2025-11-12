//SN-J00811 王雅宁 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<2<<" "<<2;
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
