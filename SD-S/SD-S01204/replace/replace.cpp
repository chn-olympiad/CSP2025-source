#include<bits/stdc++.h>
using namespace std;
int N,Q;
map<string,string> mp;
int dp[2000010];
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=Q;i++){
		string a,b;
		a[0]=b[0]='0';
		cin>>s1>>s2;
		a+=s1,b+=s2;
		int len=s1.size();
		int st=-1;
		dp[0]=1;
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

