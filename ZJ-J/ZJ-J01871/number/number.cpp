#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length(),t=0;
	for(int i=0;i<len;i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[t]=int(s[i]-'0');
			t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
