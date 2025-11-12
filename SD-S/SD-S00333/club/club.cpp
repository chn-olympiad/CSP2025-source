#include<bits/stdc++.h>
using namespace std;
int prr[100005][5];
int t,n,m,a[100005][5],num1,num2,num3,maxx;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		priority_queue<int,vector<int>,greater<int> >que1,que2,que3;
		maxx=0;
		num1=0,num2=0,num3=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
			maxx+=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
			{
				prr[i][1]=abs(a[i][1]-a[i][2]);
				prr[i][2]=abs(a[i][1]-a[i][3]);
				que1.push(min(prr[i][1],prr[i][2]));
				num1++;
			}
			else if(a[i][2]>a[i][1] && a[i][2]>a[i][3])
			{
				prr[i][1]=abs(a[i][2]-a[i][1]);
				prr[i][2]=abs(a[i][2]-a[i][3]);
				que2.push(min(prr[i][1],prr[i][2]));
				num2++;
			}
			else if(a[i][3]>a[i][2] && a[i][3]>a[i][1])
			{
				prr[i][1]=abs(a[i][3]-a[i][2]);
				prr[i][2]=abs(a[i][3]-a[i][1]);
				que3.push(min(prr[i][1],prr[i][2]));
				num3++;
			}
		}
		if(num1>m)
		{
			int o=num1-m;
			while(o--)
			{
				maxx-=que1.top();
				que1.pop();
				
			}
		}
		if(num2>m)
		{
			int oo=num2-m;
			while(oo--)
			{
				maxx-=que2.top();
				que2.pop();
			}
		}
		if(num3>m)
		{
			int ooo=num3-m;
			while(ooo--)
			{
				maxx-=que3.top();
				que3.pop();
			}
		}
		cout<<maxx<<"\n";
	}
	return 0;
}

