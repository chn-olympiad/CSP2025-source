#include <bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
int a[20];
string x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(int i=0;i<=x.size();i++){
		if(x[i]>='0'&&x[i]<='9'){
			int s=x[i]-'0';
			a[s]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
}
