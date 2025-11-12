#include <bits/stdc++.h>
using namespace std;
int cmp(char x,char y){
	return x>y;
}
string a;
int cnt;
char b[1000000]={};
int main(){
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>=48 && a[i]<=57){
			cnt++;
			b[cnt]=a[i];
		}
	}
	sort(b,b+len,cmp);
	for(int i=0;i<cnt;i++){
		cout<<b[i];
	}
	return 0;
} 
