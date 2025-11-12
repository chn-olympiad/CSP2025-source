#include<bits/stdc++.h>
using namespace std;
int T,n,s,num1,num2,num3;
const int N=1e5+10;
struct node{
	int x,y,z;
}a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		s=0;num1=0;num2=0;num3=0;
		priority_queue<int>q1,q2,q3;
	    for(int i=1;i<=n;i++)
	    {
//	    	cout<<i<<'\n';
	    	if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
	    	{
	    		s+=a[i].x;num1++;
	    		q1.push(max(a[i].y,a[i].z)-a[i].x);
	    		if(num1>n/2) s+=q1.top(),q1.pop();
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				s+=a[i].y;num2++;
				q2.push(max(a[i].x,a[i].z)-a[i].y);
				if(num2>n/2) s+=q2.top(),q2.pop();
			}
			else
			{
				s+=a[i].z;num3++;
				q3.push(max(a[i].x,a[i].y)-a[i].z);
				if(num3>n/2) s+=q3.top(),q3.pop();
			}
		}
		cout<<s<<'\n';	
	}
	return 0;
}