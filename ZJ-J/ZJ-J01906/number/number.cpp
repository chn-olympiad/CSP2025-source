#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if('0'<=c&&c<='9'){
			a[++cnt]=c-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;--i){
		cout<<a[i];
	}
	return 0;
}
