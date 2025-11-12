#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
int k[1001000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]>='0'&&s[i]<='9') k[++cnt]=s[i]-'0';
	}
	sort(k+1,k+cnt+1);
	while(k[cnt]==0){
		cnt--;
	}
	if(cnt==0) cout<<0;
	for(int i=cnt;i>=1;i--){
		cout<<k[i];
	}
	return 0;
}
