#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e6+5;
char a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size(),b=0;
	for(int i=0;i<l;i++){
		if(s[i]=='0'||s[i]=='9') {
			a[b]=s[i];
			b++;
			continue;
		}
		if(s[i]>'0'&&s[i]<'9'){
			a[b]=s[i];
			b++;
		}
	}
	sort(a,a+b);
	while(b--){
		cout<<a[b];
	}
	return 0;
}
