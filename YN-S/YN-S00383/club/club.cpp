#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int T,n,ans;
struct s
{
	int a,b,c;
}st[MAXN];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	int num1,num2,num3,t1,t2,t3;
	while(T--)
	{
		cin>>n,ans=0,num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++)
			cin>>st[i].a>>st[i].b>>st[i].c;
		for(int i=n;i>=1;i--)
		{
			if(num1<n/2&&num1<n-num2-num3)
			{
				if(num2<n/2&&num2<n-num1-num3)
					t1=st[i].a+st[i-1].b;
				if(num3<n/2&&num3<n-num1-num2)
					t1=max(t1,st[i].a+st[i-1].c);
				if(num1<n/2-1)
					t1=max(st[i].a+st[i-1].a,t1);
			}
			else
				t1=0;
			if(num2<n/2&&num2<n-num1-num3)
			{
				if(num1<n/2&&num1<n-num2-num3)
					t2=st[i].b+st[i-1].a;
				if(num3<n/2-1&&num3<n-num1-num2)
					t2=max(st[i].b+st[i-1].c,t2);
				if(num2<n/2-1)
					t2=max(st[i].b+st[i-1].b,t2);
			}
			else
				t2=0;
			if(num3<n/2&&num3<n-num1-num2)
			{
				if(num1<n/2&&num1<n-num2-num3)
					t3=st[i].c+st[i-1].a;
				if(num2<n/2&&num2<n-num1-num3)
					t3=max(st[i].c+st[i-1].b,t3);
				if(num3<n/2-1)
					t3=max(st[i].c+st[i-1].c,t3);
			}
			else
				t3=0;
			
			if(t1>=max(t2,t3)&&num1<n/2)
				ans+=st[i].a,num1++;
			else if(t2>=max(t1,t3)&&num2<n/2)
				ans+=st[i].b,num2++;
			else if(num3<n/2)
				ans+=st[i].c,num3++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
