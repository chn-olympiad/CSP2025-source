#include<bits/stdc++.h>
#define ll long long
#define N 1000001
using namespace std;
ll Asize,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++Asize]=s[i]-'0';
		}
	}
	sort(a+1,a+Asize+1);
	if(a[Asize]==0){
		cout<<0;
		return 0;
	}
	for(ll i=Asize;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
