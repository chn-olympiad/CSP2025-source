#include <bits/stdc++.h>
using namespace std;
char a[100000];
long long b[10],n=0,c,d=0;
int main(){
	std::ifstream cin("number.in");
	std::ofstream cout("number.out");
	cin>>a;
	for(int i=0;;i++){
		if(a[i]==' ') break;
		if(a[i]>='0'&&a[i]<='9'){
			c=a[i]-'0';
			b[c]++;
			continue;
		}
	}
	b[8]--,b[0]-=3,b[2]--,b[4]--;
	for(int i=9;i>=0;){
		if(i<0) break;
		if(b[i]==0){
			i--;
			continue;
		}
		cout<<i;
		b[i]--;
	}
	return 0;
}
