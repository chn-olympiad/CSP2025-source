#include<bits/stdc++.h>
using namespace std;
int mp[15],lenn;
string n;
int main()
{
//  考试结束后，必须去除注释! 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;lenn=n.size();
	for(int i=0;i<lenn;i++)
	{
		if(n[i]>='0'&&n[i]<='9')  mp[n[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=mp[i];j++)  cout<<i;
	}
	return 0;
}
