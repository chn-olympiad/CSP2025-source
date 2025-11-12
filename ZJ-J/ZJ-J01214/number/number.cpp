#include<bits/stdc++.h>
using namespace std;
int n,a[15],flag;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			flag=1;
			while(a[i]--)cout<<i;
		}
	}
	return 0;
}
