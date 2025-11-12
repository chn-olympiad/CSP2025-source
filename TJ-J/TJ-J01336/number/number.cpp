#include <bits/stdc++.h>
using namespace std;
string s,b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.in","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
        	int j=0;
        	b[j]=s[i];
        	j++;
        }
    }
    for(int q=0;q<b.length();q++){
    	for(int j=0;j<b.length();j++){
    		if(b[j]<b[j+1]&&j+1<=b.length()){
    			char x=' ';
    			x=b[j];
    			b[j]=b[j+1];
    			b[j+1]=x;
			}
		}
	}
	for(int z=0;z<b.length();z++){
		cout<<b[z];
	}
    return 0;
}
