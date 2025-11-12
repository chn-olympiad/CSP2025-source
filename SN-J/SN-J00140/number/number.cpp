//SN-J00140  刘益谦  西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
string s,c;
int a[100010]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int b = 1;
	for(int i = 0;i < s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			cout<<s[i];
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//290es1q0
