#include<bits/stdc++.h>
using namespace std;
int n,m;
string fir_in[200005],fir_q,sec_in[200005],sec_q;
bool check(int x)
{
	string fd=fir_in[x],cge=sec_in[x];
	long long pos=fir_q.find(fd);
	for(int i=pos;i<=pos+cge.size();i++)
	{
		if(sec_q[i]!=cge[i-pos]) return false;
	}
	return true;
}
bool ooo(string f)
{
	char x=f[0];
	for(int i=0;i<f.size();i++)
	{
		if(f[i]!=x) return false;
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>fir_in[i]>>sec_in[i];
	if(m>=1010)
	{
		for(int i=1;i<=m;i++) cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=m;i++) 
	{
		int ans=0;
		cin>>fir_q>>sec_q;
		if(ooo(fir_q))
		{
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			if(check(j)) ans++;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}






