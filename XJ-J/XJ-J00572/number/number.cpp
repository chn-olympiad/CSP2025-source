#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],l,bl;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		bl=s[i]-'0';
		if(bl>=0&&bl<=9){
			a[bl]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
