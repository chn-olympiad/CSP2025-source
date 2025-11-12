#include<bits/stdc++.h>
using namespace std;
string s,ans;
char c[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans+=s[i];
		}
	}
	for(int i=0;i<n;i++){
		c[i]=ans[i];
	}
	sort(c,c+n+1);
	for(int i=n;i>0;i--){
		cout<<c[i];
	}
	return 0;

}
