#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9'){
			b[c]=a[i]-'0';
			c+=1;
		}
	}
	sort(b,b+c);
	for(int i=c;i>0;i--){
		cout<<b[i-1];
	}
}
