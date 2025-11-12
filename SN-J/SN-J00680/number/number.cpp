#include<bits/stdc++.h>
using namespace std;
bool c(int p,int q){
	return p>q;
}
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			b[n]=s[i]-'0';
		}
	}
	sort(b+1,b+n+1,c);
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}
	return 0;
}

