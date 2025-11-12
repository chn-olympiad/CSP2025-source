#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
//	cout<<s.length()<<"\n";
	for(int i=0;i<s.length();i++){
//		cout<<s[i];
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
//	cout<<"\n";
	bool bl=true;
	for(int i=9;i>=0;i--){
		if(bl&&a[i]==0){
//			cout<<i<<' ';
			continue;
		}
		else if(a[i]>0){
			bl=false;
			while(a[i]--){
				cout<<i;
			}
		}
	}
	cout<<"\n";
	return 0;
}
