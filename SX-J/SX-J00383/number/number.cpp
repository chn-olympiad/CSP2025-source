#include<bits/stdc++.h>
using namespace std;
string s,ss;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0' and s[i]<='9'){
    		ss+=s[i];
		}
	}
    for(int i=0;i<ss.size();i++){
    	a[i]=(int)ss[i]-'0';
	}
	sort(a+0,a+ss.size()-1+1,cmp);
    for(int i=0;i<ss.size();i++){
		cout<<a[i];
	}
	return 0;
}