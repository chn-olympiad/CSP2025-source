#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a<b)return a>b;
	return a<b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int ans[1000010];
	int l=s.size();
	cin>>s;
	for(int i=1;i<=l;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')ans[i]+=s[i]-'0';
		sort(ans,ans+l,cmp);
		cout<<ans[i];
	}
	return 0;
}
