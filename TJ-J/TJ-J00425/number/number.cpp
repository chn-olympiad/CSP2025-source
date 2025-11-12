#include<iostream>
#include<string>
using namespace std;
int x[10];
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(-1<n[i]-'0'&&n[i]-'0'<10){
			x[9-(n[i]-'0')]++;
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<x[i];j++){
			cout<<9-i;
		}
	}
	return 0;
} 
