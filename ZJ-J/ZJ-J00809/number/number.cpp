#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ans[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int ls=s.size(),la=0;
	for(int i=0;i<ls;i++){
		if(s[i]>='0' && s[i]<='9') ans[++la]=s[i]-'0';
	}
	sort(ans+1,ans+la+1);
	for(int i=la;i>=1;i--) cout<<ans[i];
	cout<<endl;
	return 0;
}
