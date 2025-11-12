#include<bits/stdc++.h>
using namespace std;
string s;
int a[105],c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			c++;
		}
	}
	for(int i=1;i<=c;i++){
		for(int j=9;j>=0;j--){
			if(a[j]!=0){
				cout<<j;
				a[j]--;
				break;
			}
		}
	}
	return 0;
}
