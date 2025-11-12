#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char i;
	while(cin>>i){
		if(i>='0' && i<='9'){
			len++;
			a[len]=i-'0';
		}
	}
	sort(a+1,a+len+1);
	while(len--){
		cout<<a[len+1];
	}
	return 0;
}
