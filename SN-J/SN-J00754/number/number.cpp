//SN-J000754 西安市高新第二初级中学 王昊泽 
#include<bits/stdc++.h>
using namespace std;
string s;int n[10^6+5];
bool compare(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		n[i]=int(s[i])-48;
	}
	sort(n,l+n,compare);
	for(int i=0;i<l;i++){
		if(n[i]<=9 and n[i]>=0){
			printf("%d",n[i]);
		}
	}
	return 0;
}
