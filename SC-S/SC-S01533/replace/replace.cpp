#include<iostream>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a[n*2],b[m*2];
	int z[m]={},o=0;
	for(int i=0;i<n*2;i++)
		cin>>a[i];
	for(int i=0;i<m*2;i++)
	 	cin>>b[i];
	for(int i=0;i<m*2;i=i+2)
	{
		o++;
	for(int l=0;l<n*2;l=l+2)
		{
			if(a[l]==b[i])
			{
				a[l]=b[i+1];
				if(a[l]==a[l+1])
				z[o]=z[o]+2;
			}
		 } 	
	}
	for(int i=m-1;i>=0;i--)
	cout<<z[i]<<endl;
}