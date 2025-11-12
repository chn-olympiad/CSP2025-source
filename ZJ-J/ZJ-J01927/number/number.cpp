#include<bits/stdc++.h>
using namespace std;
int n,a[50];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]-'0'<0||s[i]-'0'>9)continue;
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}

