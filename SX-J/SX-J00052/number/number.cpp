#include<bits/stdc++.h>
using namespace std;

char s;
long long i=0,ai=0,a[1000001];
int main(){
	freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0'&&s<='9'){
			a[ai]=int(s-'0');


			ai++;
		}


	}
	sort(a,a+ai);
	for(int ii=ai-1;ii>=0;ii--){
		cout<<a[ii];
	}
}