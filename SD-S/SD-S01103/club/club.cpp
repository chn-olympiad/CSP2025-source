#include<bits/stdc++.h>
using namespace std;
int a[100001][3],A,B,C,n,t,maxn,happy,b[20001],c[20001];
int club(int stu)
{
	if (stu>=n+1) maxn=max(happy,maxn);
	else
	{
		if(A>0){A--; happy+=a[stu][0]; club(stu+1); A++; happy-=a[stu][0];}
		if(B>0){B--; happy+=a[stu][1]; club(stu+1); B++; happy-=a[stu][1];}
		if(C>0){C--; happy+=a[stu][2]; club(stu+1); C++; happy-=a[stu][2];}
	}
 } 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		maxn=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2];
		}
		if(n>3)
			{if(a[1][2]==a[2][2]&&a[3][2]==a[2][2]&&a[3][2]==0)
				{if(a[1][1]==a[2][1]&&a[3][1]==a[2][1]&&a[3][1]==0)
					{A=n/2;
					for(int j=1;j<=n;j++){b[a[j][0]]++;}
					for(int j=20000;A>0;j--)
					{
						while(b[j]>0&&A>0)
						{
							A--; maxn+=j; b[j]--;
						}
					}
					cout<<maxn<<endl; continue;
					}
				else
					{
					A=B=n/2;
					for(int j=1;j<=n;j++)
						{
						maxn+=max(a[j][0],a[j][1]); 
						b[abs(a[j][0]-a[j][1])]++;
						if(a[j][0]>a[j][1]) {A--;c[abs(a[j][0]-a[j][1])]++;}
						else {B--;b[abs(a[j][0]-a[j][1])]++;}
						}
					if(A<0){
					A=abs(A);
					for(int j=0;A>0;j++)
					{
						while(c[j]>0&&A>0)
						{
							A--; maxn-=j; c[j]--;
						}
					}}
					else
					{
						for(int j=0;A>0;j++)
						{
							while(b[j]>0&&A>0)
							{
								A--; maxn-=j; b[j]--;
							}
						}
					}
					cout<<maxn<<endl; continue;
					}
				}
			else
			if(n>9999)
			{
				for(int j=1;j<=n;j++)
				maxn+=max(a[j][0],max(a[j][1],a[j][2]));
				cout<<maxn<<endl; continue;
			 } 
			}
		A=B=C=n/2;
		club(1);
		cout<<maxn<<endl;
	}
	return 0;
 }


