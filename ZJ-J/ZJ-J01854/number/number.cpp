#include<bits/stdc++.h>
using namespace std;
int x[1000008],a=1;
char b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		b=s[i];
		if(b-48>=0&&b-48<=9){
			x[a]=s[i]-48;
			a++;
		}
	}
	sort(x+1,x+a);
	for(int i=a-1;i>=1;i--){
		cout<<x[i];
	}
	return 0;
}
