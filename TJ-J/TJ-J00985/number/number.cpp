#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[120000];
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1'){
			a[i]=1;
		}else if(s[i]=='2'){
			a[i]=2;
		}else if(s[i]=='3'){
			a[i]=3;
		}else if(s[i]=='4'){
			a[i]=4;
		}else if(s[i]=='5'){
			a[i]=5;
		}else if(s[i]=='6'){
			a[i]=6;
		}else if(s[i]=='7'){
			a[i]=7;
		}else if(s[i]=='8'){
			a[i]=8;
		}else if(s[i]=='9'){
			a[i]=9;
		}
	}
	sort(a+1,a+len+1);
	for(int i=len-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
