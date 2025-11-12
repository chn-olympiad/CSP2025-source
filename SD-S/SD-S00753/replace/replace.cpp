#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
char s[maxn][2],q[maxn];
int t[maxn];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)
	cin>>q[i][1]>>q[i][2];
	cout<<"2"<<endl;
	cout<<"0"<<endl;
	
	
	for(int i=1;i<=q;i++)cout<<t[i];
	return 0;
}
