#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>f(n+1);
		vector<int>s(n+1);
		vector<int>t(n+1);
		int bigst=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i]>>s[i]>>t[i];
		}
		if(s[1]==t[1]&&s[1]==0)
		{
			int ans=0;
			sort(f.begin(),f.end());
			for(int i=bigst+1;i<=n;i++)
			{
				ans+=f[i];
			}
			cout<<ans<<"\n";
		}
		else
		{
			queue<int>a;
			queue<int>b;
			queue<int>c;
			int bigst=n/2;//每个部门最大人数 
			//分别储存每个人情况，三个部门 
			vector<int>m(n+1);
			for(int i=1;i<=n;i++)
			{
				int temp;
				if(max(f[i],s[i])==f[i]&&max(f[i],t[i])==f[i])temp=1;
				else if(max(s[i],f[i])==s[i]&&max(s[i],t[i])==s[i])temp=2;
				else temp=3;//if(max(t[i],f[i])==t[i]&&max(s[i],t[i])==t[i])
				//对于哪个满意度更高
				m[i]=temp;
			}
			//m,第m[i]个人最喜欢哪个部门
			int temp1=0,temp2=0,temp3=0;
			for(int i=1;i<=m.size();i++)
			//check是否有不合法的分配 
			{
				if(m[i]==1)temp1++;
				else if(m[i]==2)temp2++;
				else temp3++;
			}
			bool flag=1;
			if(temp1>bigst||temp2>bigst||temp3>bigst)flag=0;
			if(flag==1)//直接求和合法 
			{
				for(int i=1;i<=n;i++)
				//最终安排 
				{
					if(m[i]==1)a.push(f[i]);
					else if(m[i]==2)b.push(s[i]);
					else c.push(t[i]);
				} 
			}
			//下面是计算结果 
			int ans=0;
			int sa=a.size(),sb=b.size(),sc=c.size();
			for(int i=1;i<=sa;i++)
			{
				ans+=a.front();
				a.pop();
			}
			for(int i=1;i<=sb;i++)
			{
				ans+=b.front();
				b.pop();
			}
			for(int i=1;i<=sc;i++)
			{
				ans+=c.front();
				c.pop();
			}
			cout<<ans<<"\n";
		}	
	}
	return 0;
}
//freopen("club.in","r",stdin);
//freopen("club.out","w",stdout);
