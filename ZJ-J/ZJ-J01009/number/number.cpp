#include<bits/stdc++.h>
using namespace std;
string a;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]<='9'&&a[i]>='0') cnt[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--) cout<<i;
	}
}