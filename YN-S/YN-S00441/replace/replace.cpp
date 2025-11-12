#include <bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;
map<string,string> mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) {
		cin>>s1>>s2;
		mp.insert({s1,s2});
	}
	while (m--) {
		cin>>s1>>s2;
		int l=s1.length(),ans=0;
		for (int i=0; i<l; i++)
			for (int j=1; j<=l-i; j++)
				if (mp.find(s1.substr(i,j))!=mp.end())
					if (s1.substr(0,i)+mp[s1.substr(i,j)]+s1.substr(i+j,l-i-j)==s2)
						ans++;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
