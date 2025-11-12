#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000020]={},coun=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	//is num
	for(int i=0;i<s.size();i++){
		char q=s[i];
		if(q>='0' && q<='9'){
			num[coun]=s[i];
			coun++;
		}
	}
	

	for(int i=1;i<=coun;i++){
		int number=0,times=1;
		for(int j=1;j<=i;j++){
			
		}
	}
	
	return 0;
}
