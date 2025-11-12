#include<bits/stdc++.h>
using namespace std;
string s;
int w=1,ans[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>=0){
			ans[w]=s[i]-48;
			w++;
		}
	}
	sort(ans+1,ans+w);
	for(int i=w-1;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}
