#include<bits/stdc++.h>
using namespace std;
bool a[200000001];
bool fast(int x,int y)
{
	bool z=a[x];
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]==z) z=!z;
	}
	return z;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	long long n;
	int k;
	int z=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0)
	{
			for(int i=1;i<=n;i++)
		{
			if(a[i]==0) z++;
			else if((a[i]==1)&&(a[i+1]==1)&&((i+1)<=n)) {z++;i++;}
		}
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) z++;
		}
	}
	cout<<z;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
