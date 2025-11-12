#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,s=0,s1=0;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) s=a[i];
	}
	sort(a+1,a+(m*n)+1,greater<int>());//1 4 5
	for(int i=1;i<=m*n;i++)//            2 3 6
	{
		if(s==a[i])
		{
			s1=i;
		}
	}
	int d=0;
	if(s1%n==0) d=s1/n;
	else d=s1/n+1;
	if(d%2!=0&&s1%n!=0) cout<<d<<" "<<s1%n;
	else if(d%2!=0&&s1%n==0) cout<<d<<" "<<(s1%n)+n;
	else if(d%2==0&&s1%n!=0) cout<<d<<" "<<n-(s1%n)+1;
	else cout<<d<<" "<<n-((s1%n)+n)+1;
	return 0;
}

