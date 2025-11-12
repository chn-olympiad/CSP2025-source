#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010],c=1;
int isnum(char x){
	if('9'>=x&&x>='0'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(isnum(a[i])==1){
			b[c]=a[i]-'0';
			c++;
		}
	}
	sort(b+1,b+c+1);
	for(int i=c;i>1;i--){
		cout<<b[i];
	}
	return 0;
}
