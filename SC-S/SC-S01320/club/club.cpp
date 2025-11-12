#include<bits/stdc++.h>
using namespace std;
int a[200005][3],b[200005];
struct stu{
	int t1,t2,t3,f,maxn;
}s[200005];
void check(int n)
{
	for(int i=1;i<=n;i++)
	cout<<s[i].t1<<" "<<s[i].t2<<" "<<s[i].t3<<endl;
	cout<<endl;
}
bool cmp1(stu a,stu b)
{
	return a.t1>b.t1;
}
bool cmp2(stu a,stu b)
{
	return a.t1-a.t2>b.t1-b.t2||a.t1-a.t2==b.t1-b.t2&&a.t1>b.t1;
}
bool cmp3(stu a,stu b)
{
	return a.t1-a.t2-a.t3>b.t1-b.t2-b.t3||a.t1-a.t2-a.t3==b.t1-b.t2-b.t3&&a.t1>b.t1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int maxs=n/2,s1=0,s2=0,s3=0,sum=0;
		bool f2=0,f3=0;
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0) f2=1;
			if(a[i][3]!=0) f3=1;
			s[i].t1=a[i][1],s[i].t2=a[i][2],s[i].t3=a[i][3];
			s[i].maxn=max(s[i].t1,max(s[i].t2,s[i].t3));
		}
		sort(s+1,s+1+n,cmp3);
	//	check(n);
		if(f2==0&&f3==0)
		{
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=maxs;i++)
			{
				sum+=s[i].t1;
			}
			cout<<sum<<endl;
			continue;
		}
		else if(f2==1&&f3==0)
		{
			sort(s+1,s+1+n,cmp2);
		//	check(n);
			for(int i=1;i<=maxs;i++)
			sum+=s[i].t1;
			for(int i=maxs+1;i<=n;i++)
			sum+=s[i].t2;
			cout<<sum<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i].t1==s[i].maxn)
			{
				if(s1<maxs){
				sum+=s[i].t1;
				s1++;
				}
				else
				{
					if(s[i].t2>=s[i].t3&&s2<maxs)
					{
						sum+=s[i].t2;
						s2++;
					}
					else if(s[i].t2<=s[i].t3&&s3<maxs)
					{
						sum+=s[i].t3;
						s3++;
					}
				}
			}
			if(s[i].t2==s[i].maxn)
			{
				if(s2<maxs){
				sum+=s[i].t2;
				s2++;
				}
				else
				{
					if(s[i].t1>=s[i].t3&&s1<maxs)
					{
						sum+=s[i].t1;
						s1++;
					}
					else if(s[i].t1<=s[i].t3&&s3<maxs)
					{
						sum+=s[i].t3;
						s3++;
					}
				}
			}
			if(s[i].t3==s[i].maxn)
			{
				if(s3<maxs){
				sum+=s[i].t3;
				s3++;
				}
				else
				{
					if(s[i].t2>=s[i].t1&&s2<maxs)
					{
						sum+=s[i].t2;
						s2++;
					}
					else if(s[i].t2<=s[i].t1&&s1<maxs)
					{
						sum+=s[i].t1;
						s1++;
					}
				}
			}
		}
		
		cout<<sum<<endl;
	}
	return 0;
}