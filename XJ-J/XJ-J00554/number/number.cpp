#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000002];
int k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-48;
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
