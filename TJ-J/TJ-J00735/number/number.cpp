#include<bits/stdc++.h>
using namespace std;
string s;
int n=1,c[100]; 
bool cmp(string a,string b){
	return a<b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.ans","w",stdout);
	cin>>s;
	for(int i=0;i<=1000;i++){
		if(s>="0"&&s<="9"){
			c=s;
			n++;
		}
	}
	cout<<s;
	return 0;
}

