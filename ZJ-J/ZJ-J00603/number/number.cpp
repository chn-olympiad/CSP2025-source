#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
int j=1;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j++]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=2;i--){
		cout<<a[i];
	}
	return 0;
}