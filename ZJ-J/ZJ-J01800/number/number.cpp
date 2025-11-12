#include<bits/stdc++.h>
using namespace std;
long long n,v[15];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=v[i];j++){
			cout<<i;
		}
	}
	return 0;
}
