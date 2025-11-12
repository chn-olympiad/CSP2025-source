#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[10]={0};
	cin>>a;
	for(int i=0;i<=a.length();i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
