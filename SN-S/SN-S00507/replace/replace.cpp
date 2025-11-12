#include<bits/stdc++.h>
using namespace std;
string s1,s2,zs1,zs2,ds1,ds2;
long long ld1,ld2,l1,l2,n,q,sum;
int sk(long long x,long long y)
{
	int i;
	for(i=1;s1[x-i]!=' '&&x!=i;i++) if(s1[x-i]!=ds1[y-i]||s2[x-i]!=ds2[y-1]) return 0;
	for(i=1;s1[x+i]!=' '&&x+1!=l1;i++) if(s1[x+i]!=ds1[y+i]||s2[x+i]!=ds2[y+1]) return 0;
	for(;x+i<ld1;i++) if(ds1[y+i]!=ds2[y+i]) return 0;
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q ;
	for(int i=1;i<=n;i++)
	{
		cin >> zs1 >> zs2 ;
		s1=s1+' '+zs1;s2=s2+' '+zs2;
	}
	l1=s1.size(),l2=s2.size();
	for(int cs=1;cs<=q;cs++)
	{
		sum=0;
		cin >> ds1 >> ds2 ;
		ld1=ds1.size(),ld2=ds2.size();
		if(ld1!=ld2)
		{
			cout << 0 << endl ;
			continue;
		}
		for(int i=0;i<ld1;i++)
		{
			if(ds1[i]!=ds2[i])
			{
				for(int j=0;j<l1;j++)
				{
					if(s1[j]==ds1[i]&&s2[j]==ds2[i])
					{
						sum+=sk(j,i);
					}
				}
				break;
			}
		}
		cout << sum << endl ;
	}
	return 0;
}
