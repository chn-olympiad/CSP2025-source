#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=20;
const int INF=0x3f3f3f3f;
int b[N];
string st;
inline void fre()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>st;
	int len=st.size()-1;
	for(int i=0;i<=len;i++)
		if(st[i]>='0'&&st[i]<='9') b[st[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=b[i];j>=1;j--) cout<<i;
	cout<<'\n';
	return 0;
}