#include<bits/stdc++.h>//c-replace
using namespace std;
#define int long long
int n,q;
int minn;
int len;
int cnt,sz[200006];
string a,b[200006];
string x,y;
map<string ,int> mp;
map<int ,bool> qc;
int solve()
{
	int sum=0;
	for(int k=1;k<=cnt;k++)
	{
		int t=0,w=sz[k]-1;
		while(t<len&&w<len)
		{
			string s=" ";s="";
			string s1=" ";s1="";
			for(int i=t;i<=w;i++)
			{
				s+=x[i];
				s1+=y[i];
			}
	//		cout<<"!"<<s<<"\n";//
		//	cout<<mp[s]<<"\n";//
			if(mp[s]!=0)
			{
	//			cout<<"!!"<<b[mp[s]]<<"\n";//
				if(mp[s]==mp[b[mp[s]]]&&b[mp[s]]==s1)
				{
//					cout<<mp[s]<<'\n';//
					sum++;
				}
			}
			t++;w++;
		}		
	}

	return sum;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b[i];
		int k=a.size();
		if(qc[k]==0)
		{
			sz[++cnt]=k;
			qc[k]=1;
		}
		mp[a]=i;
		mp[b[i]]=i;
	}
//	for(int k=1;k<=cnt;k++) cout<<sz[k]<<' ';//
//	cout<<'\n';//
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		len=x.size();
		cout<<solve();
		if(i!=q) cout<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

替换一次 
*/