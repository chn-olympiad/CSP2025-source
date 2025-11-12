#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000005],k;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0') a[++k]=s[i]-'0';
	}
	sort(a+1,a+k+1,[&](int a,int b){
		return a>b;
	});
	for(int i=1;i<=k;i++) cout<<a[i];
	return 0;
}
