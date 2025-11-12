#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll tot,a[1001000],n;
char str[1001000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	n=strlen(str);
	for(int i=0;i<n;i++) if(isdigit(str[i])) a[++tot]=str[i]-'0';
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--) cout<<a[i];
	return 0;
}
