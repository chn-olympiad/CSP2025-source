#include<bits/stdc++.h>
using namespace std;
string s,a;
int b[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		b[a[i]-'0']++;
	}
	
	for(int i=9;i>=0;i--){
		while(b[i]--){
			printf("%d",i);
		}
	}
	return 0;
}