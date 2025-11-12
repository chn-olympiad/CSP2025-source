#include<bits/stdc++.h>
using namespace std;
int a[100];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	int flag=0;
	for(int i=9;i>=0;i--){
		if(i!=0&&a[i]>=1){
			flag=1;
		}
		if(i!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
		else if(i==0){
			if(flag==0){
				cout<<0;
			}
			else{
				for(int j=1;j<=a[i];j++){
					cout<<i;
				}
			}
		}
	}
	return 0;
}
//not AFO
//CSP2025 RP++!!!
//ji dao wan sui!!!
//luogu uid:582006 markkkk_NBFLS
//qiu guan zhu
