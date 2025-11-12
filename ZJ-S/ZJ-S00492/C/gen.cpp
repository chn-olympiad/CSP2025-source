#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(random_device{}());
int rd(int r){return (rnd()%r+r)%r;}

void remake(string &s)
{
	string t = "";
	for(auto c:s) t += (char)('a'+rd(26));
	s = t;
}

int main()
{
	freopen("replace3.in","r",stdin);
	freopen("replace5.in","w",stdout);
	string s, t;
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d %d\n", n, m);
	while(n--)
	{
		cin>>s>>t;
		remake(s), remake(t);
		cout<<s<<' '<<t<<'\n';
	}
	return 0;
}