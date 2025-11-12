#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')t[s[i]-48]++;
	}
	string ans="";
	for(int i=9;i>=0;i--){
		while(t[i]){
			ans+=i+48;
			t[i]--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
