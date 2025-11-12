#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int js[20];
	for(int i=0;i<10;i++)js[i]=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			js[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<js[i];j++){
			b+=('0'+i);
		}
	}
	cout<<b;
	return 0;
}