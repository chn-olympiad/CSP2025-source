#include<bits/stdc++.h>
using namespace std;

int a[100]={0};
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
		cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
