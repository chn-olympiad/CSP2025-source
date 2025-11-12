#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b;
	int a[10]={0};
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		b=s[i]-'0';
		if(b>=0&&b<=9){
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
