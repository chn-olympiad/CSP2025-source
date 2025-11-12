#include<bits/stdc++.h>
using namespace std;
string s;
long long n=0;
long long a[1000]={0};
int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
