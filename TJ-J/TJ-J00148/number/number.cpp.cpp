#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
	int a[10]={};
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
        	a[s[i]-48]++;
        }
    }
    for(int j=9;j>=0;j--){
        while(a[j]){
        	cout<<j;
            a[j]--;
        }
    }
    return 0;
}
