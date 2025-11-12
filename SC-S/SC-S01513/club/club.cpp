#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline LL read()
{
	LL w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
} 
LL T,n,m1,m2,m3,ans;
struct stu{
	LL x;
	LL y;
	LL z;
	LL t;
} s[100005];
void solve()
{
	m1=0;
	m2=0;
	m3=0;
	ans=0;
	n=read();
	for(LL i=1;i<=n;i++)
	{
		s[i].x=read();
		s[i].y=read();
		s[i].z=read();
		if(s[i].x>=s[i].y&&s[i].x>=s[i].z)  
		{
             m1++; 
			 s[i].t=1; 
			 ans+=s[i].x;
        }
		if(s[i].y>=s[i].x&&s[i].y>=s[i].z)  
		{
			m2++; 
			s[i].t=2; 
			ans+=s[i].y;
		}
		if(s[i].z>=s[i].y&&s[i].z>=s[i].x)  
		{	
			m3++; 
			s[i].t=3; 
			ans+=s[i].z;
	    }
	}
    if(m1<=n/2&&m2<=n/2&&m3<=n/2)
    {
         cout<<ans<<endl;
		 return;    	
	}
    if(m1>n/2)
    {
    	LL r[m1+5],l=0;
    	bool f[m1+5];
		for(LL i=1;i<=n;i++)
    	{
    		if(s[i].t==1)
    		{
    			l++;
				r[l]=min(s[i].x-s[i].y,s[i].x-s[i].z);
				if(s[i].y>s[i].z) f[l]=1;
				if(s[i].z>s[i].y) f[l]=0; 
	         		
			}
		}
		sort(r+1,r+m1+1);
		for(LL i=1;i<=m1;i++)
		{
			if(m1<=n/2)
			{
				break;
			}
			if(m2==n/2)
			{
				if(f[i]==1) continue;
				ans-=r[i];
				m1--;
				m3++;
				continue;
			}
			if(m3==n/2)
			{
				if(f[i]==0) continue;
				ans-=r[i];
				m1--;
				m2++;
				continue; 
			}
			ans-=r[i];
			m1--;
			if(f[i]==1) m2++;
			if(f[i]==0) m3++;
		}
	}
	else if(m2>n/2){
	    LL r[m2+5],l=0;
    	bool f[m2+5];
		for(LL i=1;i<=n;i++)
    	{
    		if(s[i].t==2)
    		{
    			l++;
				r[l]=min(s[i].y-s[i].x,s[i].y-s[i].z);
				if(s[i].x>s[i].z) f[l]=1;
				if(s[i].z>s[i].x) f[l]=0; 
			}
		}
		sort(r+1,r+m2+1);
		for(LL i=1;i<=m2;i++)
		{
			if(m2<=n/2)
			{
				break;
			}
			if(m1==n/2)
			{
				if(f[i]==1) continue;
				ans-=r[i];
				m2--;
				m3++;
				continue;
			}
			if(m3==n/2)
			{
				if(f[i]==0) continue;
				ans-=r[i];
				m2--;
				m1++;
				continue; 
			}
			m2--;
			ans-=r[i];
			if(f[i]==1) m1++;
			if(f[i]==0) m3++;
		}
	}
	else if(m3>n/2)
	{
		int r[m3+5],l=0;
    	bool f[m3+5];
		for(LL i=1;i<=n;i++)
    	{
    		if(s[i].t==3)
    		{
    			l++;
				r[l]=min(s[i].z-s[i].x,s[i].z-s[i].y);
				if(s[i].x>s[i].y) f[l]=1;
				if(s[i].y>s[i].x) f[l]=0;
			}
		}
		sort(r+1,r+m3+1);
		for(LL i=1;i<=m3;i++)
		{
			if(m3<=n/2)
			{
				break;
			}
			if(m1==n/2)
			{
				if(f[i]==1) continue;
				ans-=r[i];
				m3--;
				m2++;
				continue;
			}
			if(m2==n/2)
			{
				if(f[i]==0) continue;
				ans-=r[i];
				m3--;
				m1++;
				continue; 
			}
			m3--;
			ans-=r[i];
			if(f[i]==1) m1++;
			if(f[i]==0) m2++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}