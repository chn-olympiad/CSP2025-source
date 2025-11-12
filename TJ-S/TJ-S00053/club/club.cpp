#include<bits/stdc++.h>
using namespace std;
int t,n,cnt,cnt_1[100005];
struct node
{
	int m1,m2,m3;	
}a[100005];
int m_1,m_2,m_3;
int main()
{
	cin>>t>>n;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].m1>>a[j].m2>>a[j].m3;
			if(m_1<n/2&&max(a[j].m1,max(a[j].m2,a[j].m3))==a[j].m1)
			{
				m_1++;
				cnt+=a[j].m1;
			}
			else if(m_2<n/2&&max(a[j].m1,max(a[j].m2,a[j].m3))==a[j].m2)
			{
				m_2++;
				cnt+=a[j].m2;
			}
			else if(m_3<n/2&&max(a[j].m1,max(a[j].m2,a[j].m3))==a[j].m3)
			{
				m_3++;
				cnt+=a[j].m3;
			}
		}
		cout<<cnt<<"\n";
		cnt=0;
		m_1=0;
		m_2=0;
		m_3=0;
		for(int l=1;l<=n;l++) 
		{
			cnt_1[l]=0;
		}
	}
	return 0;
}
