//李熠骁 SN-J00566 曲江市第一中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[100000];
	int m=1;
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]-'0'>=0 && a[i]-'0'<=9){
			b[m]=a[i]-'0';

			m++;
		}
	}
	sort(b+1,b+m+1);
	for(int i=m;i>1;i--){
		cout<<b[i];
	}
	return 0;
}
