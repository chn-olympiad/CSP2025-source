#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll t,n,a,b,c,k1[100010],k2[100010],k3[100010],s1,s2,s3,s,i;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		s=0;s1=0;s2=0;s3=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&a,&b,&c);
			if(a>b && a>c)
			{
				s+=a;
				s1++;
				k1[s1]=min(a-b,a-c);
			}
			else if(b>a && b>c)
			{
				s+=b;
				s2++;
				k2[s2]=min(b-a,b-c);
			}
			else
			{
				s+=c;
				s3++;
				k3[s3]=min(c-a,c-b);
			}
		}
		if(s1>n/2)
		{
			sort(k1+1,k1+s1+1);
			for(i=1;i<=s1-n/2;i++) s-=k1[i];
		}
		else if(s2>n/2)
		{
			sort(k2+1,k2+s2+1);
			for(i=1;i<=s2-n/2;i++) s-=k2[i];
		}
		else if(s3>n/2)
		{
			sort(k3+1,k3+s3+1);
			for(i=1;i<=s3-n/2;i++) s-=k3[i];
		}
		printf("%lld\n",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
