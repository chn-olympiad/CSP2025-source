#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;int n[10]={0};
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i] && a[i]<='9'){
			n[int(a[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(n[i]){
			cout<<i;n[i]--;
		}
	}
	cout<<endl;
	return 0;
}
