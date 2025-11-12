#include<bits/stdc++.h>
#define ll long long
using namespace std;
int b[1000005];
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<=l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i];
		 }
	}
	for(int i=0;i<=l;i++){
		b[i]=-1;
	}
	for(int i=0;i<=l;i++){
		if(a[i]=='9'){
			b[i]=9;
		}
		if(a[i]=='8'){
			b[i]=8;
		}
		if(a[i]=='7'){
			b[i]=7;
		}
		if(a[i]=='6'){
			b[i]=6;
		}
		if(a[i]=='5'){
			b[i]=5;
		}	
		if(a[i]=='4'){
			b[i]=4;
		}	
		if(a[i]=='3'){
			b[i]=3;
		}
		if(a[i]=='2'){
			b[i]=2;
		}
		if(a[i]=='1'){
			b[i]=1;
		}
		if(a[i]=='0'){
			b[i]=0;
		}
	}
	sort(b,b+l);
	for(int i=l;i>=0;i--){
		if(b[i]!=-1){
			cout<<b[i];
		}
	}
}
