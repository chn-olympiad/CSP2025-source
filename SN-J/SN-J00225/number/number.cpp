#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+5;
int n,m,t;
string s;
int a[11];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	cout<<endl;
	
	return 0;
}

