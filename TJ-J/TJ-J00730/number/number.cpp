#include<bits/stdc++.h>
using namespace std;
char s[10000000];
int b[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int d=0;
	int c=strlen(s);
	for(int i=0;i<=c;i++){
		if(s[i]>='0' && s[i]<='9'){
			if(s[i]=='0'){
				b[d]=0;
			}else if(s[i]=='1'){
				b[d]=1;
			}else if(s[i]=='2'){
				b[d]=2;
			}else if(s[i]=='3'){
				b[d]=3;
			}else if(s[i]=='4'){
				b[d]=4;
			}else if(s[i]=='5'){
				b[d]=5;
			}else if(s[i]=='6'){
				b[d]=6;
			}else if(s[i]=='7'){
				b[d]=7;
			}else if(s[i]=='8'){
				b[d]=8;
			}else if(s[i]=='9'){
				b[d]=9;
			} 
			d++;
		}
	}
	sort(b,b+d);
	for(int i=d-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
