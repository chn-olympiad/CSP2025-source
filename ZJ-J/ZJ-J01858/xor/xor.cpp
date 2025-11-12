#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int a1,a0;
int ml;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)a1++;
		if(a[i]==0)a0++;
	}
	if(a1==n&&k==0)
	{
		cout<<n/2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(a1+a0==n)
	{
		if(k==1)cout<<a1;
		else 
		{
			int i=1;
			while(i<=n)
			{
				if(a[i]==a[i+1]&&a[i]==1)
				{
					a0++;
					i=i+2;
				}
				else i++;
			}
			cout<<a0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
