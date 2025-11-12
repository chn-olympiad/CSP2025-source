#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000010],cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

