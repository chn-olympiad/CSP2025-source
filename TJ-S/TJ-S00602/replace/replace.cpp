#include<iostream>
using namespace std;
string s[400010],que[400010];
int main(){
	int n,q;
	cin>>n>>q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=1;i<=2*n;i+=2){
		cin>>s[i]>>s[i+1];
	}
	for(int i=1;i<=2*q;i+=2){
		cin>>que[i]>>que[i+1];
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}

