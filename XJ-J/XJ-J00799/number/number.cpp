#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
string s;
int n,a[N];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>s;n=s.size();int cnt=0;
	for(int i=0;i<n;i++) {
		if(s[i]<='9'&&s[i]>='0') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
} 
