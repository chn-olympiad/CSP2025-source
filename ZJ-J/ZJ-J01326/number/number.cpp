#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;
string s;
int a[N],cnt=0;
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,greater<int>());
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		ans+=char(a[i]+'0');
	}
	cout<<ans;
	return 0;
}
