#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int l[20];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1'){
			l[1]++;
		}
		else if(s[i]=='2'){
			l[2]++;
		}
		else if(s[i]=='3'){
			l[3]++;
		}
		else if(s[i]=='4'){
			l[4]++;
		}
		else if(s[i]=='5'){
			l[5]++;
		}
		else if(s[i]=='6'){
			l[6]++;
		}
		else if(s[i]=='7'){
			l[7]++;
		}
		else if(s[i]=='8'){
			l[8]++;
		}
		else if(s[i]=='9'){		
			l[9]++;
		}
		else if(s[i]=='0'){
			l[0]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(l[i]>=1){
			for(int j=1;j<=l[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
