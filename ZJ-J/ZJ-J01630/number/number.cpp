#include<bits/stdc++.h>
using namespace std;
int n[100010];
long long ans;
bool fs=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<=57 and s[i]>=48){
			n[ans]=int(s[i])-48;
			ans++;
		}
	}
	for(int i=0;i<ans;i++){
		if(n[i]!=0){
			fs=1;
		}
	}
	if(fs==0){
		cout<<0;
		return 0;
	}
	sort(n,n+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}
