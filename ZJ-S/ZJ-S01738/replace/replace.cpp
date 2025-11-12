#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q,lenb,lena[N];
string a[N][2],b[N][2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
		lena[i]=a[i][1].size();
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i][1]>>b[i][2];
		lenb=b[i][1].size();
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			string sa=b[i][1];
			for(int k=0;k<lenb;k++)
			{
				int tot=0,totk=k;
				while(b[i][1][totk]==a[j][1][tot]&&tot<lena[j]&&totk<lenb)
				{
					sa[totk]=a[j][2][tot];
					tot++;
					totk++;
				}
				if(tot==lena[j])
				{
					if(sa==b[i][2])
					{
						ans++;
						sa=b[i][1];
						break;
					}
					sa=b[i][1];
				}
				else sa=b[i][1];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
