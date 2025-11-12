#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10;
string s;
int a[maxn],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	s=" "+s;
	for(int i=1; i<=n; i++) 
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,cmp);
	for(int i=1; i<=cnt; i++) cout<<a[i];
	return 0;
}
