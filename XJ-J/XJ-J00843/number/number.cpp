#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
char ans[N];
int n,len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++len]=s[i];
		}
	}
	sort(ans+1,ans+1+len);
	for(int i=len;i>=1;i--)
		cout<<ans[i];
	cout<<"\n";
	return 0;
}
