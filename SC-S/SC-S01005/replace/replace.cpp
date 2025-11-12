#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Rp
{
	string c1;
	string c2;
};

int n,q;
int ans;
string s1,s2;
Rp rp[200005];
bool B;

bool is_B(string s1)
{
	bool B=true;
	int flag=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]=='b')
			flag++;
		if(flag>1)
			B=false;
		if(s1[i]!='a'&&s1[i]!='b')
			B=false;
	}
	return B;
}
void solveB()
{
	ans=0;
	int b_s1=s1.find('b');
	int b_s2=s2.find('b');
	int b_c1;
	int b_c2;
	for(int i=1;i<=n;i++)
	{
		string c1=rp[i].c1;
		string c2=rp[i].c2;
		b_c1=c1.find('b');
		b_c2=c2.find('b');
		if(b_c1<b_s1||c1.size()-b_c1-1>s1.size()-b_s1-1)
			continue;
		else if(b_c2-b_c1==b_s2-b_s1&&(c2.size()-b_c2-c1.size()+b_c1)==(s2.size()-b_s2-s1.size()+b_s1))
			ans++;
	}
	cout<<ans<<'\n';
}

signed main()
{
	freopen("relpace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>rp[i].c1>>rp[i].c2;
		B=B&is_B(rp[i].c1);
		B=B&is_B(rp[i].c2);
	}
	while(q--)
	{
	
	B=true;
	ans=0;
	cin>>s1>>s2;
	int flag=0;
	
	B=B&is_B(s1);
	B=B&is_B(s2);
	
//	if(B)
//	{
//		solveB();
//		continue;
//	}
	
	for(int i=0;i<s1.size();i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(rp[j].c1.size()+i-1>=s1.size())
				continue;
			if(s1.substr(i,rp[j].c1.size())==rp[j].c1)
			{
				string sx=s1.substr(0,i);
				string sy=rp[j].c2;
				string sz;
				if(i+rp[j].c1.size()<s1.size())
					sz=s1.substr(i+rp[j].c1.size(),n-i-rp[j].c1.size()+1);
				if(sx+sy+sz==s2)
				{
					ans++;
//					cout<<sy<<"\n";
				}
			}
		}
	}
	cout<<ans<<"\n";
	
	}
	
	return 0;
}