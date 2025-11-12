#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[10001];
	char d;
	int j=0;
	int max=-1;
	int a=0;
	for(int i=0;i<1001;i++){
		cin>>s[i];
		d=s[i];
		j++;
		if(d==' ') break;
	}
	for(int i=0;i<=j;i++){
		cout<<s[i]<<endl;
	}
return 0;
}
