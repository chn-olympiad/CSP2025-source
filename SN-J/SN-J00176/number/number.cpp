#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			n++;
			a[n-1]=s[i]-'0';
		}
	}
	sort(a,a+n);
	if(a[n-1]!=0){		
		for(int i=n-1;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
} 
