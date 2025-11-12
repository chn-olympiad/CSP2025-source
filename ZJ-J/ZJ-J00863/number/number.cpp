#include<bits/stdc++.h>
using namespace std;
int a[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	
}