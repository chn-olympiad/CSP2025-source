#include <bits/stdc++.h>
using namespace std;
int n[15];string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			for(int j=0;j<=9;j++){
				if(s[i]==j){
					n[j]++;
				}
			}
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<n[i];j++)
		cout<<i;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
