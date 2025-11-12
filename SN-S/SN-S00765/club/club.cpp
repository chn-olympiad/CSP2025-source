#include<bits/stdc++.h>
using namespace std;
long long n,T,a[100008],b[100008],c[10008],s[4];
int cmp2(int x1,int x2,int x3)
{
	if((x1>=x2&&x1<=x3)||(x1>=x3&&x1<=x2))
	return x1;
	if((x2>=x1&&x2<=x3)||(x2>=x3&&x2<=x1))
	return x2;
	if((x3>=x1&&x3<=x2)||(x3>=x2&&x3<=x1))
	return x3;
}
queue<int>q;
long long ans,cnt1,cnt2,cnt3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n;
		long long n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			cnt1=max(a[i],c[i]);
			cnt1=max(cnt1,b[i]);
			cnt2=cmp2(a[i],b[i],c[i]);
			cnt3=min(a[i],b[i]);
			cnt3=min(c[i],cnt3);	
			if(cnt1==a[i]&&cnt2==b[i]&&cnt3==c[i])
			{
					if(s[1]<=n/2)
					{
						s[1]++;
						ans+=cnt1;
					}
					else {
						if(s[2]<=(n/2))
						{
							s[2]++;
							ans+=cnt2;
					
						}
						else {
							s[3]++;
							ans+=cnt3;
						}
					}
					continue;
			}
			if(cnt1==a[i]&&cnt2==c[i]&&cnt3==b[i])
			{
					if(s[1]<=n/2)
					{
						s[1]++;
						ans+=cnt1;
					}
					else {
						if(s[3]<=(n/2))
						{
							s[3]++;
							ans+=cnt2;
						}
					}
					continue;
			}
			if(cnt1==b[i]&&cnt2==a[i]&&cnt3==c[i])
			{
					if(s[2]<=n/2)
					{
						s[2]++;
						ans+=cnt1;
					}
					else {
						if(s[1]<=(n/2))
						{
							s[1]++;
							ans+=cnt2;
						}
						continue;
					}
			}if(cnt1==b[i]&&cnt2==c[i]&&cnt3==a[i])
			{
					if(s[2]<=n/2)
					{
						s[2]++;
						ans+=cnt1;
					}
					else {
						if(s[3]<=(n/2))
						{
							s[3]++;
							ans+=cnt2;
						}
					
					}continue;
			}if(cnt1==c[i]&&cnt2==a[i]&&cnt3==b[i])
			{
					if(s[3]<=n/2)
					{
						s[3]++;
						ans+=cnt1;
					}
					else {
						if(s[1]<=(n/2))
						{
							s[1]++;
							ans+=cnt2;
						}
						else {
							s[2]++;
							ans+=cnt3;
						}
					}continue;
			}if(cnt1==c[i]&&cnt2==b[i]&&cnt3==a[i])
			{
					if(s[3]<=n/2)
					{
						s[3]++;
						ans+=cnt1;
					}
					else {
						if(s[2]<=(n/2))
						{
							s[2]++;
							ans+=cnt2;
						}
						else {
							s[1]++;
							ans+=cnt3;
						}
					}continue;
			}
			}
			cout<<ans<<endl;
			ans=0,s[1]=s[2]=s[3]=0;
		}
	
	
	return 0;
}/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

 */

