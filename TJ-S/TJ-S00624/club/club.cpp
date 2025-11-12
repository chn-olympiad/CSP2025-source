#include<bits/stdc++.h> 
using namespace std;
unsigned long long t,n,a,b,c,t0,t1,t2,cnt;
struct xs{int a[3];};
bool cmp(xs a,xs b){return max(a.a[0],max(a.a[1],a.a[2]))>max(b.a[0],max(b.a[1],b.a[2]));}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;vector<xs> x(n);
		for(int i = 0;i < n;i++) cin >> x[i].a[0] >> x[i].a[1] >> x[i].a[2];
		sort(x.begin(),x.begin()+n,cmp);
		for(int i = 0;i < n;i++)
		{
			l:;
			if(x[i].a[0]==x[i].a[1] && x[i].a[0]==x[i].a[2])
			{
				if(a<=b && a<=c){a++;cnt+=x[i].a[0];}
				if(b<=a && b<=c){b++;cnt+=x[i].a[1];}
				if(c<=a && c<=b){c++;cnt+=x[i].a[2];}
				continue;
			}
			if(x[i].a[0]>=x[i].a[1] && x[i].a[0]>=x[i].a[2])
			{
				if(a+1<=n/2){a++;cnt+=x[i].a[0];continue;}
				else
				{
					x[i].a[0]=0;
				}
			}
			if(x[i].a[1]>=x[i].a[0] && x[i].a[1]>=x[i].a[2])
			{
				if(b+1<=n/2){b++;cnt+=x[i].a[1];continue;}
				else
				{
					x[i].a[1]=0;
					goto l;
				}
			}
			if(x[i].a[2]>=x[i].a[0] && x[i].a[2]>=x[i].a[1])
			{
				if(c+1<=n/2){c++;cnt+=x[i].a[2];continue;}
				else
				{
					x[i].a[2]=0;
					goto l;
				}
			}
		}
		cout << cnt << endl;
		cnt=a=b=c=0;                                   
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
