#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[10],n=0,v=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		if(v>=9&&i==0&&a[i]!=0)a[0]=1;
		if(a[i]==0)v++;
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
