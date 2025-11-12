#include<bits/stdc++.h>
using namespace std;
bool cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[100000];
	int k=0;
	for(int i=0;i<=a.length();i++){
		if(a[i]<='9'&&a[i]>='0'){
			k++;
			b[k]=a[i]-'0';
		}
	}
	sort(b+1,b+k+1,cnt);
	for(int i=1;i<=k;i++){
		cout<<b[i];
	}
	return 0;
}
