#include<bits/stdc++.h>
using namespace std;
#define refi freopen("replace.in","r",stdin);
#define outfi freopen("replace.out","w",stdout);
int n,q;
vector<pair<string,string> > v; 
long long ans=0;
const int N=500006;
int sl[N]={0},sr[N]={0},sll[N]={0},srr[N]={0};
int main()
{
	refi
	outfi
	cin>>n>>q;
	string s1,s2;
	for(int i=0;i<n;i++)
	{
		cin>>s1>>s2;
		v.push_back(make_pair(s1,s2));
	}
	while(q--)
	{
		ans=0;
		cin>>s1>>s2;
		for(int i=0;i<v.size();i++)
		{
			string stt=v[i].first;
			string stq=v[i].second;
			int k=0;
			memset(sl,-1,sizeof(sl));
			memset(sr,-1,sizeof(sr));
			memset(sll,-1,sizeof(sll));
			memset(srr,-1,sizeof(srr));
			for(int j=0;j<s1.size()-stt.size()+1;j++)
			{
				if(s1.substr(j,stt.size())==stt)
				{
					sl[k]=j;
					sr[k]=j+stt.size()-1;
					k++;
				}
			}
			k=0;
			for(int j=0;j<s2.size()-stq.size()+1;j++)
			{
				if(s2.substr(j,stq.size())==stq)
				{
					sll[k]=j;
					srr[k]=j+stq.size()-1;
					k++;
				}
			}
			
			for(int j=0;j<k;j++)
				if(sl[j]==sll[j]&&sr[j]==srr[j]&&s1.substr(0,sl[j])==s2.substr(0,sll[j])&&s1.substr(sr[j]+1,k-sr[j])==s2.substr(srr[j]+1,k-srr[j]))
					ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 