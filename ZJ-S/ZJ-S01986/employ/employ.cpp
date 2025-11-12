#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],f;
string s;
int jc(int a){
	int s=a;
	while(--a){
		s*=a;
	}
	return s;
}
void ok1(){
	if(s[0]=='0'){
		cout<<jc(n);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(s[i]=='0'){
			f=1;
		}
	}
	if(f==0){
		cout<<0;
		exit(0);
	}
	if(m==1){
		ok1();
	}
}
