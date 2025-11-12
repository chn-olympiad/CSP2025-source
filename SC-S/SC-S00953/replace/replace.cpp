#include<bits/stdc++.h>
#define N 200005
using namespace std;

int n,q;
string s[N][2],t[N][2];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
//		string s1,s2;
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
//		string t1,t2;
		cin>>t[i][0]>>t[i][1];
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int l=0;l+s[j][0].size()-1<t[i][0].size();l++){
				int r=l+s[j][0].size()-1;
				if(t[i][0].substr(l,s[j][0].size())!=s[j][0]) continue;
				string x=t[i][0].substr(0,l),z=t[i][0].substr(r+1);
				if(x+s[j][1]+z==t[i][1]) ans++;
			}
		}
		printf("%d\n",ans);
	}
//	printf("\n%.0lf",(double)clock());
	return 0;
}//知颖你太美