#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[10]={0};
	cin>>s;
	int lin=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int j=9;j>=0;j--){
		for(int k=1;k<=a[j];k++){
			cout<<j;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//sprt
//freopen
//fclose 
