#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string s;
int ans[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int tot=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[++tot]=s[i]-'0';
		}
	}
	sort(ans+1,ans+tot+1);
	for(int i=tot;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}