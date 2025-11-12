#include<bits/stdc++.h>
using namespace std;
int cnt;
string s;
int ans[2000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++cnt]=s[i]-'0';
		}
	}
	sort(ans+1,ans+cnt+1,cmp);
	if(ans[1]==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		cout<<ans[i];
	}
	return 0;
}