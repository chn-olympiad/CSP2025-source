#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s;
    for (int i=0;i<(int)s.length();i++){
		if (((s[i]-48)<=9)&&((s[i]-48)>=0)){
			a[++top]=(int)s[i]-48;
		}
    }
    sort(a+1,a+1+top);
    if (a[top]==0)cout<<0;
    else{
		for (int i = top; i>=1;i--){
			cout <<a[i];
	}
	}
	return 0;
}
