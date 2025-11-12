#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0){
			cout<<0;
			return 0;
		}
		if(a[i]>0){
			break;
		}
		
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
