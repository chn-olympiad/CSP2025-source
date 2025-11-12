#include<bits/stdc++.h>
using namespace std;
int a,b,n[510],o[510],s,s1;
string c;
bool m[510];
void f(int x){
	if(x==a){
		s1=0;
		for(int i=0;i<a;i++){
			if(s1>=n[o[i]] or c[i]=='0'){
				s1++;
			}
		}
		s+=(a-s1>=b);
		return;
	}
	for(int j=0;j<a;j++){
		if(m[j]){
			continue;
		}
		m[j]=1;
		o[x]=j;
		f(x+1);
		m[j]=0;
	}
}
int main(){
	cin>>a>>b>>c;
	for(int i=0;i<a;i++){
		cin>>n[i];
	}
	f(0);
	cout<<s;
	return 0;
}
