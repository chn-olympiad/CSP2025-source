#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,l,ans,f[20];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	l=s.size();
	for(i=0;i<l;i++)
		if('0'<=s[i]&&s[i]<='9')
			f[s[i]-'0']++;
	for(i=9;i>=0;i--){
		if(i==0&&ans==0){
			cout<<0;
			return 0;
		}
		while(f[i]--){
			ans++;
			cout<<i;
		}
	}
	return 0;
}
