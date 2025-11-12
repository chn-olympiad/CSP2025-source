#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int k=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<s.length();i++){
		if(int(s[i]-'0')>=0&&int(s[i]-'0')<=9){
			a[k]=int(s[i]-'0');
			k++;
		}
	}
	sort(a,a+k);
	if(a[0]==0&&a[k-1]==0){
		cout<<0<<endl;
		return 0;
	}
	while(k--){
		cout<<a[k];
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
