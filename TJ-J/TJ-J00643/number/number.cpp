#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	cout<<l;
	string sz;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='0'){
				sz[0]++; 
			}
			if(s[i]=='1'){
				sz[1]++;
			}
			if(s[i]=='2'){
				sz[2]++;
			}
			if(s[i]=='3'){
				sz[3]++;
			}
			if(s[i]=='4'){
				sz[4]++;
			}
			if(s[i]=='5'){
				sz[5]++;
			}
			if(s[i]=='6'){
				sz[6]++;
			}
			if(s[i]=='7'){
				sz[7]++;
			}
			if(s[i]=='8'){
				sz[8]++;
			}
			if(s[i]=='9'){
				sz[9]++;
			}
		}
	}
	for(int i=9;i>=0;i--){
		if(sz[i]!=0){
			for(int j=1;j<=sz[i];j++){
				cout<<i;
			}
		}	
	}
	return 0;
} 
