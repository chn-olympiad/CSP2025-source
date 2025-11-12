#include <bits/stdc++.h>
using namespace std;
int t,n,a[3],midn,ma=0,p,sum,d[3],z[999999],f=0;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		for(int g=1;g<=3;g++)
		{
			d[g]=0;
		}
		sum=0;
		cin>>n;
		midn=n/2;
		for(int j=1;j<=n;j++)
		{
			ma=0;
			for(int k=1;k<=3;k++)
			{
				cin>>a[k];
				z[f]=a[k];
				f++;
			}
			sort(z,z+f+1);
			for(int s=0;s<misn;s++)
			{
				sum+=z[s];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
    D            IIIII         CCC        K     K
    D  D           I         C     C      K   K
    D     D        I        C             K  K
    D      D       I       C              KK
    D      D       I       C              KK
    D     D        I        C       C     K   K
    D   D          I         C     C      K      K
    D            IIIII        CCCC        K        K
*/