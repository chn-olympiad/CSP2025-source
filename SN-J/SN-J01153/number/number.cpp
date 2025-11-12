#include<bits/stdc++.h>
using namespace std;
string s[1000005];
int q[1000005];
int p,l,o;
int main(){
	
	while(cin>>p){
		s[l]=p;
		l++;
	}
	for(int i=0;i<l;i++){
		if(s[i]==1){
			q[o]=s[i];
			o++;
			break;
		}
		if(s[i]==2){
			q[o]=s[i];
			o++;
			break;
		}
		if(s[i]==3){
			q[o]=s[i];
			o++;
			break;
		}
		if(s[i]==4){
			q[o]=s[i];
			o++;
			break;
		}
		if(s[i]==5){
			q[o]=s[i];
			o++;
			break;
		}
		if(s[i]==6){
			q[o]=s[i];
			o++;
			break;
		}
		if(s[i]==7){
			q[o]=s[i];
			o++;
			break;
		}
		if(s[i]==8){
			q[o]=s[i];
			o++;
			break;
		}
		if(s[i]==9){
			q[o]=s[i];
			o++;
			break;
		}
	}
	for(int i=0;i<o;i++){
		cout<<q[i];
	}
	return 0;
}
