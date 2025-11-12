#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+8;
struct number
{
	int s1,s2,s3,no;
}num[MAXN];
int n;
int qz12[MAXN],qz23[MAXN],qz13[MAXN];
int getans(int idx,int c1,int c2,int c3)
{
	if(idx==n)
	{
		if(c1==0)return max(num[idx].s2,num[idx].s3);
		else if(c2==0)return max(num[idx].s1,num[idx].s3);
		else if(c3==0)return max(num[idx].s2,num[idx].s1);
		else return max(num[idx].s1,max(num[idx].s2,num[idx].s3));
	}
	if(c1==0)return qz23[idx];
	else if(c2==0)return qz13[idx];
	else if (c3==0)return qz12[idx];
	else
	{
		int ans=0;
		if(num[idx].no==1)ans=max(num[idx].s2+getans(idx+1,c1,c2-1,c3),num[idx].s3+getans(idx+1,c1,c2,c3-1));
		else if(num[idx].no==2)ans=max(num[idx].s1+getans(idx+1,c1-1,c2,c3),num[idx].s3+getans(idx+1,c1,c2,c3-1));
		else if(num[idx].no==3)ans=max(num[idx].s2+getans(idx+1,c1,c2-1,c3),num[idx].s1+getans(idx+1,c1-1,c2,c3));
		else ans=max(max(num[idx].s2+getans(idx+1,c1,c2-1,c3),num[idx].s1+getans(idx+1,c1-1,c2,c3)),num[idx].s3+getans(idx+1,c1,c2,c3-1));
		return ans;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(qz12,0,sizeof(qz12));
		memset(qz13,0,sizeof(qz13));
		memset(qz23,0,sizeof(qz23));
		for(int i=1;i<=n;i++)
		{
			cin>>num[i].s1>>num[i].s2>>num[i].s3;
			int s1=num[i].s1,s2=num[i].s2,s3=num[i].s3;
			if(s1<s2&&s1<s3)num[i].no=1;
			if(s2<s3&&s2<s1)num[i].no=2;
			if(s3<s2&&s3<s1)num[i].no=3;
		}
		for(int i=n;i>=n/2+1;i--)
		{
			qz12[i]=qz12[i+1]+max(num[i].s1,num[i].s2);
			qz23[i]=qz23[i+1]+max(num[i].s2,num[i].s3);
			qz13[i]=qz13[i+1]+max(num[i].s1,num[i].s3);
		}
		cout<<getans(1,n/2,n/2,n/2)<<endl;
	}
	return 0;
 } 
