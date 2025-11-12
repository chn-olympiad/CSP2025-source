#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
string s;
int a[maxn],cnt;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')	a[++cnt]=s[i]-48;
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i;--i)	cout<<a[i];
	
	return 0;
}