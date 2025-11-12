#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
string str[N][2],ask[N][2];
void solve1()
{
	int ans=0;
	string ss=ask[1][0],tt=ask[1][1];
	if(ss.size()!=tt.size()){cout<<0<<endl;return ;}
	int left_diff,right_diff,diff_len_min,check=0;
	for(int i=0;i<ss.size();i++)
	{
		if(check==0&&ss[i]!=tt[i])left_diff=i,check++;
		if(ss[i]!=tt[i])right_diff=i;
	}
	diff_len_min=right_diff-left_diff+1;
	for(int i=1;i<=n;i++)
	{
		if(str[i][0].size()<diff_len_min)continue;
		int lens=str[i][0].size(),len_cha=str[i][0].size()-diff_len_min;
		for(int j=left_diff-len_cha;j<=left_diff;j++)
		{
			if(str[i][0]==ss.substr(j,lens)&&str[i][1]==tt.substr(j,lens))ans++;
		}
	}
	cout<<ans<<endl;
	return ;
}
void solve2()
{
	int chazhi[N]={};
	for(int i=1;i<=n;i++)
	{
		int temp1,temp2;
		for(int j=0;j<str[i][0].size();j++)
		{
			if(str[i][0][j]=='b')temp1=j;
			if(str[i][1][j]=='b')temp2=j;
		}
		chazhi[i]=temp2-temp1;
	}
	sort(chazhi+1,chazhi+1+n);
	for(int i=1;i<=m;i++)
	{
		if(ask[i][0].size()!=ask[i][1].size()){cout<<0<<endl;continue;}
		int temp1,temp2,lens;
		for(int j=0;j<ask[i][0].size();j++)
		{
			if(ask[i][0][j]=='b')temp1=j;
			if(ask[i][1][j]=='b')temp2=j;
		}
		lens=temp2-temp1;
		int findout=lower_bound(chazhi+1,chazhi+n+1,lens)-chazhi;
		int findout2=upper_bound(chazhi+1,chazhi+n+1,lens)-chazhi;
		cout<<findout2-findout<<endl;
	}
	return ;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>str[i][0]>>str[i][1];
	for(int i=1;i<=m;i++)cin>>ask[i][0]>>ask[i][1];
	if(m==1){solve1();return 0;}
	bool flag=true;
	for(int i=1;i<=m;i++)
		for(int j=0;j<ask[i][0].size();j++)if(ask[i][0][j]!='a'&&ask[i][0][j]!='b')flag=false;
	for(int i=1;i<=m;i++)
		for(int j=0;j<ask[i][1].size();j++)if(ask[i][1][j]!='a'&&ask[i][1][j]!='b')flag=false;
	if(flag){solve2();return 0;}
	for(int i=1;i<=m;i++)cout<<0<<endl;
	return 0;
}
