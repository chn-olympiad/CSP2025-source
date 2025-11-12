#include<bits/stdc++.h>
using namespace std;
int flg,flg1,ans,t,n,ans1,j1,j2;
priority_queue<int> m;
priority_queue< int,vector<int>,greater<int> > m1;
struct club{
	int q1,q2,q3;
}a[100005];
int main()
	{freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;	
	while(t--)
		{cin>>n;
		ans=0;
		ans1=0;
		flg=0;
		flg1=0;
		j1=0;
		j2=0;
		for(int i=1;i<=n;i++)
			{cin>>a[i].q1>>a[i].q2>>a[i].q3;
			if(flg1==0)
			{	m1.push(max(a[i].q1,a[i].q2)-min(a[i].q1,a[i].q2));
				if(a[i].q1>a[i].q2)
					{j1++;
					if(j1>n/2)
						{j1=n/2;
						ans1+=a[i].q1;
						ans1-=m1.top();
						m1.pop();
						}
					else if(j1<=n/2)
						{ans1+=a[i].q1;
						}
					}
				if(a[i].q1==a[i].q2)
					{if(j1<n/2)
						{ans1+=a[i].q1;
						j1++;
						}
					else 
						{ans1+=a[i].q2;
						j2++;
						}
					}
			if(a[i].q1<a[i].q2)
						{j2++;
						if(j2>n/2)
							{j2=n/2;
							ans1+=a[i].q2;
							ans1-=m1.top();
							m1.pop();
							}
						else
							{ans1+=a[i].q2;
							}
						}
				
			}
			m.push(a[i].q2);
			if(a[i].q1!=0||a[i].q3!=0)
				flg=1;
			if(a[i].q3!=0)
				flg1=1;
			}
		if(n==2)
			{
			if(max(a[1].q1,max(a[1].q2,a[1].q3))==a[1].q1&&max(a[2].q1,max(a[2].q2,a[2].q3))==a[2].q1)
				{cout<<a[1].q1+a[2].q1-min(a[1].q1-a[1].q2,min(a[1].q1-a[1].q3,min(a[2].q1-a[2].q2,a[2].q1-a[2].q3)))<<endl;
				continue;
				}
			if(max(a[1].q1,max(a[1].q2,a[1].q3))==a[1].q2&&max(a[2].q1,max(a[2].q2,a[2].q3))==a[2].q2)
				{cout<<a[1].q2+a[2].q2-min(a[1].q2-a[1].q1,min(a[1].q2-a[1].q3,min(a[2].q2-a[2].q1,a[2].q2-a[2].q3)))<<endl;
				continue;
				}
			if(max(a[1].q1,max(a[1].q2,a[1].q3))==a[1].q3&&max(a[2].q1,max(a[2].q2,a[2].q3))==a[2].q3)
				{cout<<a[1].q3+a[2].q3-min(a[1].q3-a[1].q1,min(a[1].q3-a[1].q2,min(a[2].q3-a[2].q1,a[2].q3-a[2].q2)))<<endl;
				continue;
				}
			else	
				{cout<<max(a[1].q1,max(a[1].q2,a[1].q3))+max(a[2].q1,max(a[2].q2,a[2].q3))<<endl;
				continue;
				}
			}
		else if(flg==0)
			{for(int i=1;i<=n/2;i++)
				{ans+=m.top();
				m.pop();
				}
			cout<<ans<<endl;
			}
		else if(flg1==0)
			{cout<<ans1<<endl;
			}
		}
	return 0;
	}

