#include<iostream> 
#include<algorithm> 
using namespace std;
int main()
{/**/
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a[5005]={},n/*,h[5005]={}*/;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long h=0,c=1,ans=0,i,cnt=0;
	for(long long now=1;now<(1ll<<(n));now++)
	{
		h=0;c=0;cnt=0;
		i=now;
		//cout<<i<<endl;
		while(1)
		{
			if(i==1)
			{
				if(h>a[c]*2&&cnt>=2)
					ans++;
				break;
			}
			else if(i%2==1)
			{
				//cout<<c<<' ';
				h+=a[c];
				cnt++;
			}
			c++;
			i=i/2;
		}
		//cout<<endl;
	}/*
	for(int i=1;i<=n;i++)
	{
		h[i]=h[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)
	{
		if(a[i+1]*2>=h[i])
		{
			
		}
	}*/
	cout<<ans;
	return 0;
}
