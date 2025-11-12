#include<iostream> 
#include<cstring>
using namespace std;
int a[500005]={},n,k,h[500005]={},ne[500005]={},hx[500005]={};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	///*
	//cout<<'-';
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		h[i]=(h[i-1]^a[i]);
	}
	memset(ne,0x3f,sizeof(ne));
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((h[i-1]^h[j])==k)
			{
				ne[i]=j;
				break;
			}
		}
		//cout<<ne[i]<<' ';
	}
	//cout<<endl;
	memset(hx,0x3f,sizeof(hx));
	for(int i=n;i>=1;i--)
	{
		hx[i]=min(hx[i+1],ne[i]);
	}/*
	for(int i=1;i<=n;i++)
	{
		cout<<hx[i]<<' ';
	}*/
	//cout<<endl;
	//cout<<endl<<"--"<<endl;
	int now=1,ans=0;
	while(now<=n)
	{
		if(hx[now]<=n)
			ans++;
		now=hx[now]+1;
	}
	//cout<<"---"<<endl;
	cout<<ans<<'\n';//*/
	return 0;
}
