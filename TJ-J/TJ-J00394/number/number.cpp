#include <bits/stdc++.h>
using namespace std;
string s;
string p="0123456789";
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<=9;j++){
			if(s[i]==p[j]){
				a[j]+=1;
				break;
			}
		}
	}for(int i=9;i>=0;i--){
		if(a[i]>0){
			for(int j=0;j<a[i];j++) cout<<i;
		}
	}
	return 0;
}
