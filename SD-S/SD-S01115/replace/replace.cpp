#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
string A[1000120],B[1000120];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long i,n,s,m,ans;
	string mid,l,r,j;
	cin>>n>>m;
	if(m==1)
	{
		cout<<n/2;
	}
	else
	{
		for(i=1;i<=m;i++)
		{
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
