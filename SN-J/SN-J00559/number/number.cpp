#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int ls=s1.size();
	for(int i=0;i<ls;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			num[s1[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			s2+=char(i+'0');
		}
	}
	cout<<s2;
	return 0;
}
