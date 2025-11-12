#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int s[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=sizeof(a);
	for(int i=0;i<len;i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			s[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(s[i]--){
			cout<<i;
		}
	}
	return 0;
} 
