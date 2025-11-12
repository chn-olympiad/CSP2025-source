#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cin in
#define cout out
#define endl '\n'
int main(){
	fstream in,out;
	in.open("number.in",ios::in);
	out.open("number.out",ios::out);
	string a;
	cin >>a ;
	int n[16]={};
	int l=a.length();
	for(int i=0;i<l;i++){
		if(a[i]>='0' && a[i]<='9'){
			n[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=0;k<n[i];k++){
			cout << i;
		}
	}
	return 0;
}
