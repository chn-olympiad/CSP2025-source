#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int q1,q2,q3;
	int c;
}a[100005];
int n,w1,w2,w3,r1[100005],r2[100005],r3[100005],ans,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int qwe=1;qwe<=t;qwe++)
	{
	cin>>n;
	ans=0;
		w1=0;w2=0;w3=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].q1>>a[i].q2>>a[i].q3;
		if(a[i].q1>a[i].q2)
		{
			if(a[i].q1>a[i].q3)
			{
				w1++;
				ans+=a[i].q1;
				if(a[i].q2>a[i].q3)
				{
					a[i].c=a[i].q1-a[i].q2;
				}
				else{
					a[i].c=a[i].q1-a[i].q3;
				}
				r1[w1]=a[i].c;
			}
			else{
				w3++;
				ans+=a[i].q3;
				if(a[i].q2>a[i].q1)
				{
					a[i].c=a[i].q3-a[i].q2;
				}
				else{
					a[i].c=a[i].q3-a[i].q1;
				}
				r3[w3]=a[i].c;
			}
		}
		else if(a[i].q2>a[i].q3)
		{
			w2++;
			ans+=a[i].q2;
			if(a[i].q1>a[i].q3)
			{
				a[i].c=a[i].q2-a[i].q1;
			}
			else{
				a[i].c=a[i].q2-a[i].q3;
			}
			r2[w2]=a[i].c;
		}
		else{
			w3++;
			ans+=a[i].q3;
			a[i].c=a[i].q3-a[i].q2;
			r3[w3]=a[i].c;
		}
	}
	if(w1*2>n)
	{
		sort(r1+1,r1+w1+1);
		for(int i=1;i<=w1-(n/2);i++)
		{
			ans-=r1[i];
		}
	}
	else if(w2*2>n)
	{
		sort(r2+1,r2+w2+1);
		for(int i=1;i<=w2-(n/2);i++)
		{
			ans-=r2[i];
		}
	}
	else if(w3*2>n)
	{
		sort(r3+1,r3+w3+1);
		for(int i=1;i<=w3-(n/2);i++)
		{
			ans-=r3[i];
		}
	}
	cout<<ans<<"\n";
}
return 0;
}
