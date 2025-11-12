#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[107]={0},n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		int x=a[i];
		while(x--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}