#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int nu[13];
bool ks=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>s;
	for(int i=0;i<=10;++i){
		nu[i]=0;
	}
	for(int i=0;i<s.size();++i){
		if('0'<=s[i] and s[i]<='9'){
			nu[(int)s[i]-48]++;
		}
	}
	for(int i=9;i>=0;--i){
		if(nu[i]!=0)ks=true;
		if(ks==true){
			for(int j=1;j<=nu[i];++j){
				cout<<i;
			}
		}
	}
	return 0;
}
