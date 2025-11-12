#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string s;
int t[1000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>s;int n=s.size();
	int m=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9') t[m++]+=s[i]-'0';
	}
	sort(t,t+m);
	while(m>0){
		cout<<t[m-1];
		m--;
	}
	return 0;
}
