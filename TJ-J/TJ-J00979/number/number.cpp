#include <bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int z,int y){
	return z>=y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
	int l;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[l]=s[i]-'0';
    		l++;
    	}
	}sort(a,a+l,cmp);
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
    return 0;
}
