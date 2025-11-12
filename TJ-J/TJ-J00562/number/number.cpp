#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int s[1000001];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	char n[1000001];
	cin>>n;
	int lenn=n.size();
	for(int i=0;i<lenn;i++){
		a[i]=n[i]-48;
	}
	sort(a,a+lenn);
	for(int j=lenn;j>=0;j--){
		cout<<a[j];
	}
	return 0;
}
