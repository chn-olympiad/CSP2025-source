#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt=0,a[1000005];
signed main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0){
		cout << 0 << '\n';
		return 0;
	}
	else{
		for(int i = cnt;i >= 1;i--) cout << a[i];
		cout << '\n';
	}
	return 0;
}
