#include<iostream>
#include<algorithm>
using namespace std;
int n,ans;
int a[5010],t[5005];
//int f[5010][5010];

void m_polygon(int step,int ll,int beg,int sum,int Max)
{
	if(step==ll)
	{
//		for(int i=1;i<=ll;i++)
//		{
//			cout<<b[i]<<" ";
//		}
//		cout<<endl;
		if((Max*2)<sum)
		{
			ans++;	
		}
	}
	for(int i=beg+1;i<=n;i++)
	{
//		cout<<step<<" "<<ll<<" "<<i<<""<<sum+a[i]<<endl;
		if(t[i]==0)
		{
//			b[step+1]=i;
			t[i]=1;
			m_polygon(step+1,ll,i,sum+a[i],max(Max,a[i]));
			t[i]=0;
		}
		
	}
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n);
	for(int i=3;i<=n;i++)	
	{
//		cout<<i<<" "<<ans<<endl;
		m_polygon(0,i,0,0,0);	
	}
	cout<<ans%998244353;
	return 0;
} 
