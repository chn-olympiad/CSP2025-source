#include<bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
using namespace std;
int len[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			len[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(len[i]--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
