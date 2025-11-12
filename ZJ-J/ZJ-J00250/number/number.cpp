#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+4;
string s;
int a[maxn],x,l,cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	  if(s[i]>='0'&&s[i]<='9')
	    a[++x]=s[i]-'0';
	sort(a+1,a+1+x,greater<long long>());
	for(int i=1;i<=x;i++)
	  cout<<a[i];
	return 0;
}
