#include<bits/stdc++.h>
using namespace std;
int a[100010][3];
int b1[100010],b2[100010],b3[100010];
int x1,x2,x3,sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		x1=x2=x3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]==max(max(a[i][0],a[i][1]),a[i][2]))
			{
				b1[++x1]=a[i][0]-max(a[i][1],a[i][2]);
			}
			else 
			{
				if(a[i][1]==max(max(a[i][0],a[i][1]),a[i][2]))
				b2[++x2]=a[i][1]-max(a[i][0],a[i][2]);
				else 
				b3[++x3]=a[i][2]-max(a[i][0],a[i][1]);
			}
		}
		sum=0;
		int t1=0,t2=0,t3=0;
		sort(b1+1,b1+1+x1);
		sort(b2+1,b2+1+x2);
		sort(b3+1,b3+1+x3);
		int c1,c2,c3;
		c1=c2=c3=0;
		for(int i=1;i<=n;i++)
		{
			sum+=max(max(a[i][0],a[i][1]),a[i][2]);
			if(a[i][0]==max(max(a[i][0],a[i][1]),a[i][2]))t1++;
			else 
			{
				if(a[i][1]==max(max(a[i][0],a[i][1]),a[i][2]))t2++;
				else t3++;
			}
			if(t1>n/2)
			{
				sum-=b1[++c1];
				t1--;
			}
			if(t2>n/2)
			{
				sum-=b2[++c2];
				t2--;
			}
			if(t3>n/2)
			{
				sum-=b3[++c3];
				t3--;
			}
		}
		cout<<sum<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
