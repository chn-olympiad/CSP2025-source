#include<bits/stdc++.h>
using namespace std;
int tong[11]={};
int t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			tong[s[i]-'0']++;
			if(s[i]>'0') t=1;
		}
	}
	if(t==0) {
		cout << 0;
		return 0;	
	}
	for(int i=9;i>=0;--i){
		if(tong[i]>0){
			for(int j=1;j<=tong[i];++j){
				cout<<i;
			}
		}
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}

