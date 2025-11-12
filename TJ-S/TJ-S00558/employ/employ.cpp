#include <iostream> 
#include <cstdio>
using namespace std;
long long n,p;
string sp;
long long cop[1001];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>p;
	cin>>sp;
	for(long long i=1;i<=n;i++)
	{
		cin>>cop[i];
	}
	long long ans=1;
	long long sum=0;
	if(sp[1]=='1'&&sp[2]=='1'&&sp[3]=='1'&&sp[4]=='1'&&sp[5]=='1'&&sp[6]=='1'&&sp[7]=='1'&&sp[8]=='1'&&sp[9]=='1'&&sp[10]=='1'&&sp[11]=='1'&&sp[12]=='1'&&sp[13]=='1'&&sp[14]=='1'&&sp[15]=='1'&&sp[16]=='1'&&sp[17]=='1'&&sp[18]=='1'&&sp[19]=='1'&&sp[20]=='1'&&sp[21]=='1'&&sp[22]=='1'&&sp[23]=='1'&&sp[24]=='1'&&sp[25]=='1'&&sp[26]=='1'&&sp[27]=='1'&&sp[28]=='1'&&sp[29]=='1'&&sp[30]=='1')
	{
		for(long long i=1;i<=n;i++)
		{
			if(cop[i]>0)
			{
				sum++;
			}
		}
		for(long long i=2;i<=sum;i++)
		{
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	
	else if(p=1||p=n)
	{
		for(long long i=1;i<=n;i++)
		{
			if(cop[i]>0)
			{
				sum++;
			}
		}
		for(long long i=2;i<=sum;i++)
		{
			ans=(ans*i)/%998244353;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
