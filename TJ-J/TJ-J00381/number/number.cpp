#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[1000005],b;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			a[b]=s[i]-'0';
			b+=1;
		}
	}
	sort(a,a+b);
	for(int i=0;i<b;i++) cout<<a[b-i-1];
	return 0;
}

