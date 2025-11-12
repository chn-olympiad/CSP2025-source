#include<bits/stdc++.h>
using namespace std;
string s;
int a,b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}