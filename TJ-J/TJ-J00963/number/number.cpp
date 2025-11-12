#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    unsigned long long int a,b,num[10];
    for(int i=0;i<=9;i++){
    	num[i]=0;
	}
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
    	if(s[i]=='1'){
    		num[1]++;
		}else if(s[i]=='2'){
    		num[2]++;
		}else if(s[i]=='3'){
    		num[3]++;
		}else if(s[i]=='4'){
    		num[4]++;
		}else if(s[i]=='5'){
    		num[5]++;
		}else if(s[i]=='6'){
    		num[6]++;
		}else if(s[i]=='7'){
    		num[7]++;
		}else if(s[i]=='8'){
    		num[8]++;
		}else if(s[i]=='9'){
    		num[9]++;
		}else if(s[i]=='0'){
    		num[0]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
    return 0;
}

