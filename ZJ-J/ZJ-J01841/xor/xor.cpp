#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],s,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(s==k)
			{
				cout<<s<<" ";
				i=j-1;
				s=-1;
				sum++;
				break;
			}
			s^=a[j];
		}
		if(s==k)
		{
			cout<<s<<" ";
			sum++;
			break;
		}
	}
	cout<<sum;
	return 0;
}
