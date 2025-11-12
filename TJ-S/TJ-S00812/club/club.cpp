#include<bits/stdc++.h>
using namespace std;
struct nw
{
	int a1,a2,a3;
	int ma,mid,mi;
}a[100005];
bool cmp(nw q1,nw q2)
{
	if(q1.ma-q1.mid<q2.ma-q2.mid)
	{
		return false;
	}
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin >> t ;
	while(t)
	{
		t--;
		long long n,fst[4]={0,0,0,0},ans=0;
		cin >> n ;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3 ;
			a[i].ma=max(a[i].a1,max(a[i].a2,a[i].a3));
			a[i].mi=min(a[i].a1,min(a[i].a2,a[i].a3));
			a[i].mid=a[i].a1+a[i].a2+a[i].a3-a[i].ma-a[i].mi;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			//cout << a[i].ma << " " << a[i].mid << " " << a[i].mi << endl ;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].ma==a[i].a1)
			{
				//cout << 1 << " " ;
				if(fst[1]<n/2)
				{
					fst[1]++;
					ans+=a[i].a1;
				}
				else if(a[i].mid==a[i].a2)
				{
					if(fst[2]<n/2)
					{
						fst[2]++;
						ans+=a[i].a2;
					}
					else
					{
						fst[3]++;
						ans+=a[i].a3;
					}
				}
				else
				{
					fst[3]++;
					ans+=a[i].a3;
				}
			}
			else if(a[i].ma==a[i].a2)
			{
				//cout << 2 << " " ;
				if(fst[2]<n/2) 
				{
					fst[2]++;
					ans+=a[i].a2;
				}
				else if(a[i].mid==a[i].a1)
				{
					if(fst[1]<n/2)
					{
						fst[1]++;
						ans+=a[i].a1;
					}
					else
					{
						fst[3]++;
						ans+=a[i].a3;
					}
				}
				else
				{
					fst[3]++;
					ans+=a[i].a3;
				}
			}
			else
			{
				//cout << 3 << " " ;
				if(fst[3]<n/2)
				{
					fst[3]++;
					ans+=a[i].a3;
				}
				else if(a[i].mid==a[i].a1)
				{
					if(fst[1]<n/2)
					{
						fst[1]++;
						ans+=a[i].a1;
					}
					else
					{
						fst[2]++;
						ans+=a[i].a2;
					}
				}
				else
				{
					fst[2]++;
					ans+=a[i].a2;
				}
			}
			//cout << fst[1] << fst[2] << fst[3] << endl ;
		}
		cout << ans << endl ;
 	} 
 	return 0;
} 
