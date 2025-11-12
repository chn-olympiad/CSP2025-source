#include <bits/stdc++.h>
using namespace std;

const int N=15,mod=998244353;
int a[N];
string difficulty;
bool flg[N];
int c[N],n,m,cnt=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>difficulty;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=i;
		flg[i]=(difficulty[i-1]=='1');
	}
	do
	{
		int fail_cnt=0,enrolled=0;
		for(int i=1;i<=n;i++)
		{
			if(c[a[i]]<=fail_cnt)
			{
				fail_cnt++;
			}
			else if(flg[i])
			{
				enrolled++;
			}
			else
			{
				fail_cnt++;
			}
		}
		if(enrolled>=m)
		{
			cnt++;
			cnt%=mod;
		}
		
	}while(next_permutation(a+1,a+n+1));
	cout<<cnt<<endl;
}
