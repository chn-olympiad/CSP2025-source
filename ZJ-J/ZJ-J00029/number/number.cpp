#include<bits/stdc++.h>
using namespace std;
long long k,a[1000005];string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for (int i=0;i<s.size();i++) if (s[i]>=48&&s[i]<=57) a[++k]=s[i]-48;
	sort(a+1,a+k+1);
	for (int i=k;i>=1;i--) cout<<a[i];
}