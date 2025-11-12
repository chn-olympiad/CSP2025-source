#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
