#include<bits/stdc++.h>
using namespace std;
int main(){//0 48  9 57
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; 
	cin>>s;
	int ans[s.size()];
	int a=0;
	for(long long i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[a]=s[i]-48;
			a++;
			
		}
	}
	sort(ans,ans+a+1);
	for(int i=a-1;i>=0;i--){
		cout<<ans[i]; 
	}
	
	
}
