#include<bits/stdc++.h>
using namespace std;
int a,b,c,d[1000000];
string x;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>x;
	a=x.size();
	for(int i=0;i<a;i++){
		if(int(x[i])-'0'>9){
			continue;
		}
		c++;
		d[c]=int(x[i])-'0';
	}
	sort(d+1,d+1+c);
	for(int i=c;i>=1;i--){
		cout<<d[i];
	}
	return 0;
} 
