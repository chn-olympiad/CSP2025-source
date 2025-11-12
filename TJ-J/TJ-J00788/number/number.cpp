#include <bits/stdc++.h>
using namespace std;
int x[1000010];
int ans=1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			x[ans]=s[i]-'0';
			ans++;
		}
	}
	sort(x+1,x+ans+1);
	for(int i=ans;i>=1;i--){
		cout<<x[i];
	}
	return 0;
	
} 
