#include<bits/stdc++.h>
using namespace std;
int a[101010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int collapsarr=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<endl;
	int Revitalize; 
	int Qaaxaap,uitwaaien,pulsar=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2)for(int j=1;j<=n;j++)
		{
			pulsar++;
			if(a[pulsar]==collapsarr) 
			{
				uitwaaien=j;
				Qaaxaap=i;
				break;
			}
		}
		else for(int j=n;j>=1;j--)
		{
			pulsar++;
			if(a[pulsar]==collapsarr) 
			{
				uitwaaien=j;
				Qaaxaap=i;
				break;
			}
		}
	}
	cout<<Qaaxaap<<' '<<uitwaaien;
	return 0;
}
