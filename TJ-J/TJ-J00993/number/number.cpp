#include<bits/stdc++.h>
using namespace std;
string s;
char ans[1000005];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt+=1;
			ans[cnt]+=s[i];
		}
	}
	sort(ans+1,ans+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++){
		cout<<ans[i];
	}	
}
