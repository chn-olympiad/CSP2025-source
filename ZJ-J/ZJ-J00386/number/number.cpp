#include<bits/stdc++.h>
using namespace std;
int n,a[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]<='9'){
			int t=int(s[i]-'0');
			a[t]++;
		}  
	} 
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)
		  cout<<i;
	}
	return 0;
}
