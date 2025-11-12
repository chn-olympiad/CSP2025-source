#include <bits/stdc++.h>

using namespace std;
struct aaaaa
{
	int cl1,cl2,cl3;
}a[100010];
int b[100010];
int n;
int sum;
int zma;
int yifen;
int lcl1,lcl2,lcl3;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			b[i] = 0;
			cin>>a[i].cl1>>a[i].cl2>>a[i].cl3;
		}
		sum = 0;
		lcl1 = 0;
		lcl2 = 0;
		lcl3 = 0;
		zma = n/2;
		yifen = 0;
		while(yifen<n)
		{
			int ma = -999999999;
			int lmacl = -1,lmast = -1;
			for(int i = 1;i<=n;i++)
			{
				if(ma<a[i].cl1&&lcl1<zma&&b[i]==0) ma = a[i].cl1,lmacl = 1,lmast = i;
				if(ma<a[i].cl2&&lcl2<zma&&b[i]==0) ma = a[i].cl2,lmacl = 2,lmast = i;
				if(ma<a[i].cl3&&lcl3<zma&&b[i]==0) ma = a[i].cl3,lmacl = 3,lmast = i;
			}
			yifen++;
			sum += ma;
			if(lmacl==1) lcl1++;
			if(lmacl==2) lcl2++;
			if(lmacl==3) lcl3++;
			b[lmast] = 1;
//			cout<<sum<<endl;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
