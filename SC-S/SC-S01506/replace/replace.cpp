#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string a[200002],b[200002],op,op1;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--)
	{
		cin>>op>>op1;
		if(op.size()!=op1.size())
		{
			cout<<"0\n";
			continue;
		}
		int ans=0;
		int st=0,ed=op.size();
		while(st<op.size()&&op[st]==op1[st]) st++;
		while(ed>=0&&op[ed]==op1[ed]) ed--;
		for(int i=1;i<=n;i++)
		{
			auto it=op.find(a[i]),it1=op1.find(b[i]);
			if(it!=op.npos&&it1!=op1.npos&&it==it1)
			{
				string qwq=op;
				for(int j=it;j<=it+a[i].size()-1;j++)
					qwq[j]=b[i][j-it];
				if(qwq==op1) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
暴力！10pts~25pts
对于每一次询问，我们都枚举一遍n，再依次判断是否能
替换及替换后一不一样。时间O(n|op|) 
*/