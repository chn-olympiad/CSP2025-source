#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int t;
int cnt(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[t++]=s[i]-'0';
		}
	}
	sort(a,a+t,cnt);
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
	return 0;
}
