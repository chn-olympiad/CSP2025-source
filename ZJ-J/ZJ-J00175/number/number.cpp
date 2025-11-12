#include<bits/stdc++.h>
using namespace std;
long long L,k,a[10000005];
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	while(cin>>s[++L])
		if(s[L]>='0'&&s[L]<='9')a[++k]=s[L]-48;
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++)cout<<a[i];
	return 0;
}                      