#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	string ans;
	int num=0;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		char a;
		a=(char)s[i];
		if(a-'0'>=0 && a-'0'<=9){
			ans+=s[i];
			num++;
		}
		a=0;
	}
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			if((ans[i]-'0')>(ans[j]-'0'))swap(ans[i],ans[j]);
			else continue;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
