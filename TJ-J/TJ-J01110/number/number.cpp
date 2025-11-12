#include<bits/stdc++.h>
using namespace std;
int a[100];
string s;
int main(){
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=100005;i++){
		a[int(s[i])-48]++;
	}
	for(int i=1;i<=9;i++){
		for(int j=a[i];j>=1;j++){
			cout<<i;
		}
	}
	return 0;
}
