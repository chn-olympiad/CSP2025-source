#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+300;
string change[N][3],a,b;
int n,q,num;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>change[i][1]>>change[i][2];
	while(q--)
	{
		num=0;
		cin>>a>>b;
		int l=a.size();
		for(int i=1;i<=n;i++)
		{
			int pos = a.find(change[i][1]);
			while(pos>=0 && pos<n)
			{
				string c=a;
				for(int j=pos;j<=pos-1+change[i][1].size();j++)
					c[j]=change[i][2][j-pos];
				if(b==c)
					num++;	
				pos = a.find(change[i][1], pos+1);
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
