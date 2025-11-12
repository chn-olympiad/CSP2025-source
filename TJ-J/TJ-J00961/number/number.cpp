#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length(),b[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')b[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(b[i]--)cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
