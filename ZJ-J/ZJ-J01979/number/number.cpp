#include<bits/stdc++.h>
using namespace std;
int ans[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(47<s[i] && s[i]<58){
			ans[j]=s[i]-48;
			j++;
		}
	}
	sort(ans,ans+j);
	for(int i=j-1;i>=0;i--){
		printf("%d",ans[i]);
	}
	return 0;
}
