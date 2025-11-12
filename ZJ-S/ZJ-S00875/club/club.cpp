#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int x[100001][3];
int a[100001],b[100001],c[100001];
int amn=0,bmn=0,cmn=0;//class-member-number
void merry()//merry-go-around
{
	int va[30000],mxv=-1,mnv=99999,ov,al=0,bl=0,cl=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i][0]>>x[i][1]>>x[i][2];
		if(x[i][0]>=x[i][1])
		{
			if(x[i][0]>=x[i][2]){a[++al]=i;ans+=x[i][0];}
			else {c[++cl]=i;ans+=x[i][2];}
		}
		else
		{
			if(x[i][1]>=x[i][2]) {b[++bl]=i;ans+=x[i][1];}
			else {c[++cl]=i;ans+=x[i][2];}
		}
	}
	if(al>n/2)
	{
		ov=al-n/2;
		for(int i=1;i<=al;i++)
		{
			int v=min(x[a[i]][0]-x[a[i]][1],x[a[i]][0]-x[a[i]][2]);
			va[v]++;
			if(mnv>v) mnv=v;
			if(mxv<v) mxv=v;
		}
		for(int i=mnv;i<=mxv;i++)
		{
			if(va[i]>=ov)
			{
				ans-=ov*i;
				break;
			}
			else
			{
				ans-=va[i]*i;
				ov-=va[i];
			}
		}
	}
	else if(bl>n/2)
	{
		ov=bl-n/2;
		for(int i=1;i<=bl;i++)
		{
			int v=min(x[b[i]][1]-x[b[i]][0],x[b[i]][1]-x[b[i]][2]);
			va[v]++;
			if(mnv>v) mnv=v;
			if(mxv<v) mxv=v;
		}
//		cout<<mnv<<' '<<mxv<<endl;
		for(int i=mnv;i<=mxv;i++)
		{
			if(va[i]>=ov)
			{
				ans-=ov*i;
				break;
			}
			else
			{
				ans-=va[i]*i;
				ov-=va[i];
			}
		}
	}
	else if(cl>n/2)
	{
		ov=cl-n/2;
		for(int i=1;i<=cl;i++)
		{
			int v=min(x[c[i]][2]-x[c[i]][0],x[c[i]][2]-x[c[i]][1]);
			va[v]++;
			if(mnv>v) mnv=v;
			if(mxv<v) mxv=v;
		}
//		cout<<mnv<<' '<<mxv<<endl;
		for(int i=mnv;i<=mxv;i++)
		{
			if(va[i]>=ov)
			{
				ans-=ov*i;
				break;
			}
			else
			{
				ans-=va[i]*i;
				ov-=va[i];
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int mili=1;mili<=t;mili++) merry();
	fclose(stdin);fclose(stdout);
	return 0;
}
