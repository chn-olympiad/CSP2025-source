#include<bits/stdc++.h>
using namespace std;
string s; 
int a[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
} 
