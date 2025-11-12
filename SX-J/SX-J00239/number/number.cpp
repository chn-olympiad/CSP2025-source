#include <bits/stdc++.h>
using namespace std;
char c[1000005],ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),sum=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') {
			sum++;
			c[sum]=s[i];
		}
	}
	int p=0;
	for(int i=1;i<=sum;i++){
		if(c[i]=='9'){
			p++;
			ans[p]='9';
			c[i]=='!';
		}
	}
	for(int i=1;i<=sum;i++){
		if(c[i]=='8'){
			p++;
			ans[p]='8';
			c[i]=='!';
		}
	}
	for(int i=1;i<=sum;i++){
		if(c[i]=='7'){
			p++;
			ans[p]='7';
			c[i]=='!';
		}
	}
	for(int i=1;i<=sum;i++){
		if(c[i]=='6'){
			p++;
			ans[p]='6';
			c[i]=='!';
		}
	}for(int i=1;i<=sum;i++){
		if(c[i]=='5'){
			p++;
			ans[p]='5';
			c[i]=='!';
		}
	}
	for(int i=1;i<=sum;i++){
		if(c[i]=='4'){
			p++;
			ans[p]='4';
			c[i]=='!';
		}
	}
	for(int i=1;i<=sum;i++){
		if(c[i]=='3'){
			p++;
			ans[p]='3';
			c[i]=='!';
		}
	}for(int i=1;i<=sum;i++){
		if(c[i]=='2'){
			p++;
			ans[p]='2';
			c[i]=='!';
		}
	}for(int i=1;i<=sum;i++){
		if(c[i]=='1'){
			p++;
			ans[p]='1';
			c[i]=='!';
		}
	}for(int i=1;i<=sum;i++){
		if(c[i]=='0'){
			p++;
			ans[p]='0';
			c[i]=='!';
		}
	}
	for(int i=1;i<=sum;i++) cout<<ans[i];
	return 0;
}