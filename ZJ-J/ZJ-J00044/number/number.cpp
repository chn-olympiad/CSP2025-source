#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ct=0;
	for (int i=0;i<s.size();++i){
		if (s[i]>='0' && s[i]<='9'){
			a[++ct]=s[i]-'0';
		}		
	}
	sort(a+1,a+1+ct,cmp);
	for (int i=1;i<=ct;++i){
		cout<<a[i];
	}
	return 0;
}
