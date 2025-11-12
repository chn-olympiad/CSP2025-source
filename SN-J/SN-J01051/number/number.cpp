#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n=0,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s; 
	n=s.size();
	for(int i=0;i<=n;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[i]=int(s[i])-48;
			cout<<a[i];
			t++;
		}
	}
	/*for(int i=0;i<=t-1;i++){
		cout<<a[i];
	}*/
	return 0;
} 
