#include<bits/stdc++.h>
using namespace std; 
string a;
long long b,c[1000000],d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	b=a.size();
	for(int i=0;i<b;i++){
		if(char(a[i])>='0'&&char(a[i])<='9'){
			c[d]=int(char(a[i])-'0');
			d++;
		}
	}
	sort(c,c+d);
	if(c[d-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=d-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
}
