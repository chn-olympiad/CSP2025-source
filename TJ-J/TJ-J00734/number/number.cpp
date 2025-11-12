#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s,a;
    char c[1000001];
    int j=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
        	c[j++]=s[i];
		}
    }
    sort(c,c+j);
    for(int i=j-1;i>=0;i--){
    	a+=c[i];
	}
	cout<<a;
    return 0;
}
