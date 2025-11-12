#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int d1,d2,d3;
	int v;
}a[N];
int T;
int tmp[3];
bool cmp(node a,node b)
{
	return a.v>b.v;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n,cnt1,cnt2,cnt3;
		long long ans=0;
		cnt1=cnt2=cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			tmp[0]=a[i].d1,tmp[1]=a[i].d2,tmp[2]=a[i].d3;
			sort(tmp,tmp+3);
			a[i].v=tmp[2]-tmp[1];
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			tmp[0]=a[i].d1,tmp[1]=a[i].d2,tmp[2]=a[i].d3;
			sort(tmp,tmp+3);
			for(int j=2;j>=0;j--)
			{
				if(tmp[j]==a[i].d1&&cnt1<n/2) 
				{
					ans+=a[i].d1,cnt1++;
					break;
				}
				else if(tmp[j]==a[i].d2&&cnt2<n/2) 
				{
					ans+=a[i].d2,cnt2++;
					break;
				}
				else if(tmp[j]==a[i].d3&&cnt3<n/2)
				{
					ans+=a[i].d3,cnt3++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
