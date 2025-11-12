#include <bits/stdc++.h>
using namespace std;
int b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int lena=a.size(),j=1;
	for(int i=0;i<lena;++i){
		if(a[i]>='0' && a[i]<='9'){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b+1,b+1+j);
	for(int i=j;i>1;i--){
		cout<<b[i];
	}
	return 0;
}
