#include<bits/stdc++.h>
#define ll long long
using namespace std;
int kp[5000010];
string kmp(string a,string b)
{
	string ans="";
	int cpr=0;
	kp[0]=0;
	for(int i=1;i<b.size();i++)
	{
		if(b[i]==b[kp[i-1]])
			kp[i]=kp[i-1]+1;
		else
		{
			if(kp[i-1]==0)
			{
				kp[i]=0;
				continue;
			}
			if(b[i]==b[kp[kp[i-1]-1]])
				kp[i]=kp[kp[i-1]-1]+1;
			else
				kp[i]=0;
		}
	}
	for(int i=0,f=0;i<a.size();)
	{
		if(a[i]==b[f])
		{
			i++;
			f++;
			if(f==b.size())
			{
				f=kp[f-1];
				ans=ans+"1";
			}
			else
				ans=ans+"0";
		}
		else
		{
			if(f)
				f=kp[f-1];
			else
				i++,ans=ans+"0";
		}
	}
	return ans;
}
const int MAX=2e5+10;
int n,q;
string fr[MAX],sd[MAX],qta,qtb;
int fl[MAX],sl[MAX],al,bl;
int ans;
int cnt;
int bg,ed;
bool sp;
//#define test
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	#ifdef test
	freopen("replace1.in","r",stdin);
	#else
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>fr[i]>>sd[i];
	for(int i=0;i<q;i++)
	{
		ans=0;
		cin>>qta>>qtb;
		string a,b;
		for(int f=0;f<n;f++)
		{
			cnt=0;
//			cout<<fr[f]<<' '<<sd[f]<<'\n';
			a=kmp(qta,fr[f]);
			b=kmp(qtb,sd[f]);
			for(int j=0;j<a.size();j++)
				if(a[j]-'0'&&b[j]-'0')cnt++;
			if(cnt==1)ans++;
//			cout<<a<<' '<<b<<'\n';
		}
		cout<<ans<<'\n';
	}
}