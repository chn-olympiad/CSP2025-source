#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x[s.size()],y=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			x[y]=0;
			y++;
		}else if(s[i]=='1'){
			x[y]=1;
			y++;
		}else if(s[i]=='2'){
			x[y]=2;
			y++;
		}else if(s[i]=='3'){
			x[y]=3;
			y++;
		}else if(s[i]=='4'){
			x[y]=4;
			y++;
		}else if(s[i]=='5'){
			x[y]=5;
			y++;
		}else if(s[i]=='6'){
			x[y]=6;
			y++;
		}else if(s[i]=='7'){
			x[y]=7;
			y++;
		}else if(s[i]=='8'){
			x[y]=8;
			y++;
		}else if(s[i]=='9'){
			x[y]=9;
			y++;
		}
	}
	int a[y],b=0;
	for(int i=0;i<y;i++){
		if(x[i]==9){
			a[b]=9;
			b++;
		}
	}
	for(int i=0;i<y;i++){
		if(x[i]==8){
			a[b]=8;
			b++;
		}
	}for(int i=0;i<y;i++){
		if(x[i]==7){
			a[b]=7;
			b++;
		}
	}
	for(int i=0;i<y;i++){
		if(x[i]==6){
			a[b]=6;
			b++;
		}
	}
	for(int i=0;i<y;i++){
		if(x[i]==5){
			a[b]=5;
			b++;
		}
	}for(int i=0;i<y;i++){
		if(x[i]==4){
			a[b]=4;
			b++;
		}
	}
	for(int i=0;i<y;i++){
		if(x[i]==3){
			a[b]=3;
			b++;
		}
	}
	for(int i=0;i<y;i++){
		if(x[i]==2){
			a[b]=2;
			b++;
		}
	}for(int i=0;i<y;i++){
		if(x[i]==1){
			a[b]=1;
			b++;
		}
	}
	for(int i=0;i<y;i++){
		if(x[i]==0){
			a[b]=0;
			b++;
		}
	}
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	
	
	
	return 0;
} 
