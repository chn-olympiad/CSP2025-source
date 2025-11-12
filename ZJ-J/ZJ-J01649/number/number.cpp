#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt[15];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	int l=0;
	for(int i=9;i>=0;i--){
		if(l==0&&i==0)continue;
		l+=cnt[i];
		while(cnt[i]--)cout<<i;
	}
	return 0;
}
