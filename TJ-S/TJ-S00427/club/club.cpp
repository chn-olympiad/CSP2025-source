#include "bits/stdc++.h"
using namespace std;
struct clup
{
	int st;
	int nd;
	int rd;
	int maxa,maxb,maxc;
}clubb[100005];
int sum;
int one;
int two;
int three;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,j,k=0,m,h;
	cin>>t;
	while(k<t)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>clubb[i].st>>clubb[i].nd>>clubb[i].rd;
		}
		for(i=1;i<=n;i++)
		{
			if(clubb[i].st<clubb[i].nd)
			{
				if(clubb[i].st<clubb[i].rd)
				{
					if(clubb[i].nd<clubb[i].rd)
					{
						clubb[i].maxa=clubb[i].rd;
						clubb[i].maxb=clubb[i].nd;
						clubb[i].maxc=clubb[i].st;
						three++;
						sum+=clubb[i].rd;
					}
					else
					{
						clubb[i].maxa=clubb[i].nd;
						clubb[i].maxb=clubb[i].rd;
						clubb[i].maxc=clubb[i].st;
						two++;
						sum+=clubb[i].nd;
					}					
				}
				else
				{
					clubb[i].maxa=clubb[i].nd;
					clubb[i].maxb=clubb[i].st;
					clubb[i].maxc=clubb[i].rd;
					two++;
					sum+=clubb[i].nd;
				}
			}
			else
			{
				if(clubb[i].nd<clubb[i].rd)
				{
					if(clubb[i].st<clubb[i].rd)
					{
						clubb[i].maxa=clubb[i].rd;
						clubb[i].maxb=clubb[i].st;
						clubb[i].maxc=clubb[i].nd;
						three++;
						sum+=clubb[i].rd;
					}	
					else
					{
						clubb[i].maxa=clubb[i].st;
						clubb[i].maxb=clubb[i].rd;
						clubb[i].maxc=clubb[i].nd;
						one++;
						sum+=clubb[i].st;
					}			
				}
				else
				{
					clubb[i].maxa=clubb[i].st;
					clubb[i].maxb=clubb[i].nd;
					clubb[i].maxc=clubb[i].rd;
					one++;
					sum+=clubb[i].st;
				}
			}
		}
		m=n/2;
		if(one>m)
		{
			h=one-m;
			for(i=1;i<=h;i++)
			{
				sum=sum-clubb[i].maxa+clubb[i].maxb;
			}	
		}
		if(two>m)
		{
			h=two-m;
			for(i=1;i<=h;i++)
			{
				sum=sum-clubb[i].maxa+clubb[i].maxb;
			}	
		}
		if(three>m)
		{
			h=three-m;
			for(i=1;i<=h;i++)
			{
				sum=sum-clubb[i].maxa+clubb[i].maxb;
			}	
		}
		cout<<sum<<endl;
		sum=0;
		k++;
	}
	return 0;
}
