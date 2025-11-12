#include<bits/stdc++.h>
using namespace std;
int a[10000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
    string s;
    cin>>s;
    int len=s.size(),cnt=0;
    for(int i=0;i<len;i++){
    	if(s[i]<='9' && s[i]>='0'){
        a[i]=s[i]-'0';
        cnt++;
		}
	}
	sort(a,a+len,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}