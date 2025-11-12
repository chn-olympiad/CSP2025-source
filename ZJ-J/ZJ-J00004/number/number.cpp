#include<bits/stdc++.h>
using namespace std;
int a[1000100],num=1;
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if('0'<=c&&c<='9'){
			a[num]=c-'0';
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}