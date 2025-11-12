#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000010];
int cnt=1;
int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			ans[cnt++]=x;
		}
	}
	sort(ans+1,ans+cnt,cmp);
	for(int i=1;i<cnt;i++){
		cout<<ans[i];
	}
	return 0;
}