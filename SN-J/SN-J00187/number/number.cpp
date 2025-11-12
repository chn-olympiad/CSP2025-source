#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define float double
using namespace std;
string S;
int ans;
int T[15];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>S;
	int l=S.size();
	for(int i=0;i<l;i++)
		if(S[i]>='0' && S[i]<='9')
			T[S[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=T[i];j++)
			cout<<i;
	cout<<'\n';
	
	return 0;
}

