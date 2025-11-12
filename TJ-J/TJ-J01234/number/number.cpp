#include <bits/stdc++.h>

using namespace std;

const int N=1e6;
int ans[N],pos,cnt=0;

bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			ans[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(ans,ans+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout << ans[i];
	}
	return 0;
}
