#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1[201010],s2[201010];
vector<unsigned int> hs1[201010],hs2[201010];
unsigned int mhas[200];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=128;i++) mhas[i]=(unsigned int)rand();
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		hs1[i].push_back(0);
		hs2[i].push_back(0);
		for(int j=0;j<s1[i].size();j++)
			hs1[i].push_back(hs1[i][j]+mhas[s1[i][j]]);
		for(int j=0;j<s2[i].size();j++)
			hs2[i].push_back(hs2[i][j]+mhas[s2[i][j]]);
		s1[i]='#'+s1[i];
		s2[i]='#'+s2[i];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		t1='#'+t1;
		t2='#'+t2;
		int l=1,r=t1.size()-1;
		while(t1[l]==t2[l]) l++;
		while(t1[r]==t2[r]) r--;
//		cout<<' '<<l<<' '<<r<<endl;
//		string q1,q2="";
//		for(int i=l;i<=r;i++) q1+=t1[i];
//		for(int i=l;i<=r;i++) q2+=t2[i];
		unsigned int hq1=0,hq2=0;
		int ans=0;
		for(int i=l;i<=r;i++) hq1+=mhas[t1[i]],hq2+=mhas[t2[i]];
		//cout<<"hq:"<<hq1<<' '<<hq2<<endl;
		for(int ii=1;ii<=n;ii++)
		{
			//cout<<"siz:"<<s1[ii].size()-1<<endl;
			if(s1[ii].size()-1<r-l+1) continue;
			int flag=0,st,en;
			for(int i=r-l+1;i<s1[ii].size();i++) 
			{
				//cout<<"    "<<i<<endl;
//				cout<<(hs1[ii][i]-hs1[ii][i-1-r+l])<<' '<<(hs2[ii][i]-hs2[ii][i-1-r+l])<<endl;
				if(((hs1[ii][i]-hs1[ii][i-1-r+l])==hq1)&&((hs2[ii][i]-hs2[ii][i-1-r+l])==hq2)) 
				{
					st=i-r+l;
					en=i;
					flag=1;
					break;
				}
			}
//			cout<<"f"<<flag<<endl;
//			cout<<"st"<<st<<' '<<"en"<<en<<endl;
			if(!flag) continue;
			if(st>l) continue;
			if(s1[ii].size()-1-en>t1.size()-1-r) continue;
			for(int i=1;st-i>=1;i++) 
			{
//				cout<<"cl1  "<<st-i<<endl;
//				cout<<"cl2  "<<l-i<<endl;
				if(s1[ii][st-i]!=t1[l-i]||s2[ii][st-i]!=t2[l-i]) flag=0;
			} 
			for(int i=1;i+en<s1[ii].size();i++)
			{
//				cout<<"cr1  "<<i+en<<endl;
//				cout<<"cr2  "<<i+r<<endl;
				if(s1[ii][en+i]!=t1[r+i]||s2[ii][en+i]!=t2[r+i]) flag=0;
			}
//			cout<<"f:"<<flag<<endl;
			ans+=flag;
		}
		cout<<ans<<endl;
	}
	return 0;
}
