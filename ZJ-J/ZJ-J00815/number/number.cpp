#include<bits/stdc++.h>
using namespace std;
string s;
int a[15]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>=48&&s[i]<=57){
			a[(int)(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;//#Shang4Shan3Ruo6Shui4
}
