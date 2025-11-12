#include<bits/stdc++.h> 
using namespace std;
string s;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[0]++;
		}else if(s[i]=='1'){
			a[1]++;
		}else if(s[i]=='2'){
			a[2]++;
		}else if(s[i]=='3'){
			a[3]++;
		}else if(s[i]=='4'){
			a[4]++;
		}else if(s[i]=='5'){
			a[5]++;
		}else if(s[i]=='6'){
			a[6]++;
		}else if(s[i]=='7'){
			a[7]++;
		}else if(s[i]=='8'){
			a[8]++;
		}else if(s[i]=='9'){
			a[9]++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(a[9]!=0){
			cout<<9;
			a[9]--;
		}else if(a[8]!=0){
			cout<<8;
			a[8]--;
		}else if(a[7]!=0){
			cout<<7;
			a[7]--;
		}else if(a[6]!=0){
			cout<<6;
			a[6]--;
		}else if(a[5]!=0){
			cout<<5;
			a[5]--;
		}else if(a[4]!=0){
			cout<<4;
			a[4]--;
		}else if(a[3]!=0){
			cout<<3;
			a[3]--;
		}else if(a[2]!=0){
			cout<<2;
			a[2]--;
		}else if(a[1]!=0){
			cout<<1;
			a[1]--;
		}else if(a[0]!=0){
			cout<<0;
			a[0]--;
		}else if(a[0]==0){
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
