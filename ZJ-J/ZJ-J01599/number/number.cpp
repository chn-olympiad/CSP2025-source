#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1;
int ans[N];
string ch;
bool cmp(int a,int b){return a>b;}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>ch;
	for(int i=0;i<ch.size();++i)
		if(ch[i]>='0'&&ch[i]<='9') ans[++ans[0]]=ch[i]-'0';
	sort(ans+1,ans+1+ans[0],cmp);
	for(int i=1;i<=ans[0];++i) cout<<ans[i];
}
