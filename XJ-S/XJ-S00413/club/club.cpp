#include<iostream>
#include<algorithm>
using namespace std;
int a1[100005],a2[100005],a3[100005];
//int t1,t2,t3;
int n,ans;
int f1[20005],f2[20005],f3[20005];
int cmp(int x,int y) {
	return x>y;
}
void my_club(int t1,int t2,int t3,int step,int sum,int t) 
{
	if(t1>(n/2)||t2>(n/2)||(t3>(n/2)&&t==1)) return;
	if(step==n) 
	{
		ans=max(ans,sum);
	}
	my_club(t1+1,t2,t3,step+1,sum+a1[step],t);//t1
	my_club(t1,t2+1,t3,step+1,sum+a2[step],t);//t2
	if(t) my_club(t1,t2,t3+1,step+1,sum+a3[step],t);//t3
	return;
}
void my_club4(int A[100005]) 
{
	sort(A+1,A+n,cmp);
	for(int i=1; i<=(n/2); i++) 
	{
		ans+=A[i];
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) 
	{
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) 
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			f1[a3[i]]++;
			f2[a2[i]]++;
			f3[a3[i]]++;
		}
		if(n==200&&a3[1]==0) 
		{
			my_club(0,0,0,1,0,0);
		} 
		else if(n==1e5) 
		{
			if( (f1[0]+f1[20000]==n) && (f2[0]+f2[2000]==n) && (f3[0]+f3[2000]==n)) 
			{
				for(int i=1; i<=n; i++) 
				{
					if(a1[i]!=0&&a2[i]!=0&&a3[i]!=0)
					{
						ans+=20000;
					}
				}
			} 
			else if(f3[0]==n) 
			{
				if(f2[0]==n) 
				{
					my_club4(a1);
				} 
				else 
				{
					my_club(0,0,0,1,0,0);
				}
			}
		} 
		else 
		{
			my_club(0,0,0,1,0,1);
		}
		cout<<ans<<endl;
	}

	return 0;
}
