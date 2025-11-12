#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,p;
	int b[10000000];
	cin>>s;
	int n=s.size();
	int m=p.size();
	for(int i=0;i<n;i++){
		if(s[i]<=9&&s[i]>=1){
			p[i]=s[i];
		}
	}
	for(int j=0;j<m;j++){
		if(p[j]>p[j-1]){
			b[j]=p[j-1];
			p[j-1]=p[j];
			p[j]=b[j];
		}
	}
}
