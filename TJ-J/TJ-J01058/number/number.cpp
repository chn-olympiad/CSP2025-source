#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;

int n,cnt;
string s;
int ans[N];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++cnt]=s[i]-'0';
		}
	}
	sort(ans+1,ans+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<ans[i];
	return 0;
}
