#include<bits/stdc++.h>
using namespace std;
string x;
int number[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]>='0'&&x[i]<='9')number[x[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(number[i]>0){
			cout<<i;
			number[i]--;
		}
	}
}
