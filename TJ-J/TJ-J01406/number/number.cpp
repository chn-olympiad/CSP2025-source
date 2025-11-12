#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000020];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int p=0;
	for(int i=0;i<=a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			p=p+1;
			b[p]=a[i]-'0';
		}
	}
	sort(b+1,b+1+p,cmp);
	for(int i=1;i<=p;i++){
		cout << b[i];
	}
	return 0;
}
