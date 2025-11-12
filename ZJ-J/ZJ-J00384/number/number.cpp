#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t="";
ll sum=0;
int b[20]={0};
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	sum=s.size();
	for(int i=0; i<sum; i++){
		int a=s[i]-48;
		if(a>=0&&a<=9){
			b[a]++;
		}
	}
	for(int i=9; i>=0; i--){
		if(b[i]>0){
			for(int j=1; j<=b[i]; j++){
				cout<<i;
			}
		}
	}
	return 0;
}

