#include<bits/stdc++.h>
using namespace std;
int xors[500005],sum[500005];
int sk_place=0;
int binarytoint(bool x[],int i)
{
	int ret=0;
	while(i>=1)
	{
		if(x[i])
		{
			ret=ret*2+1;
		}
		else
		ret=ret*2;
		i--;
	}
	return ret;
}
int xorsum(int x,int y)
{
	bool retbinary[500005];
	int i=0;
	while(x!=0||y!=0)
	{
		i++;
		if(x%2!=y%2)
		{
			retbinary[i]=1;
		}
		else
		retbinary[i]=0;
		x/=2;
		y/=2;
	}
	return binarytoint(retbinary,i);
}
int main()
{
	fstream file=fstream("xor.in",ios::in);
	fstream file2=fstream("xor.out",ios::out);
	int n,k,ans=0;
	file>>n>>k;
	for(int i=1;i<=n;i++)
	{
		file>>sum[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=max(i,sk_place+1);j<=n;j++)
		{
			if(i==j)
			{
				xors[j]=sum[i];
			}
			else if(i+1==j)
			{
				xors[j]=xorsum(sum[i],sum[j]);
			}
			else
			{
				xors[j]=xorsum(xors[j-1],sum[j]);
				//file2<<sum[j]<<"=";
			}
			//file2<<xors[j]<<" ";
			if(xors[j]==k)
			{
				ans++;
				//file2<<"ans add,now:"<<ans<<",in:"<<i<<","<<j<<endl;
				sk_place=j;
				break;
			}
		}
		//file2<<endl;
	}
	file2<<ans;
	return 0;
}