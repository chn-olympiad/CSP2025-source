#include<bits/stdc++.h>
using namespace std;
char n[10000005];
long long cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[++cnt]=s[i];
		}
	}
	sort(n+1,n+1+cnt);
	for(int i=cnt;i>0;i--){
		cout<<n[i];
	}
	return 0;
}
