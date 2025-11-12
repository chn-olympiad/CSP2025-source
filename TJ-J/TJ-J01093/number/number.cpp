#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    while(cin>>s){
    	for(int i=0;i<s.size();i++){
    	    if(s[i]>='0'&&s[i]<='9'){
    		    int t=int(s[i]-'0');
    		    a[t]++;
	        }
	    }
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
