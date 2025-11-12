#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long A[2000000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long i,m,n,s=0,x1,x2,x3,z,k;
	cin>>n>>m>>k;
	if(k!=0)
	{
		cout<<n*k+m<<endl;
	}
	else
	{
		for(i=1;i<=m;i++)
		{
			cin>>x1>>x2>>A[i];
		}
		sort(A+1,A+1+n);
		for(i=1;i<n;i++)
		{
			s+=A[i];
		}
		cout<<s<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
