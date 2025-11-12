#include<bits/stdc++.h>
#define ll long long

using namespace std;
string x;
char s[100000050];
int a[100000050],lon;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll i=0;
	while(s[i]!='\0'){
		if(s[i]<='9'&&s[i]>='0'){
			lon++;
			a[lon]=s[i]-'0';
		}
		i++;
	}
	sort(a,a+lon+1);
	if(a[1]==0){
		printf("0");
		return 0;
	}
	for(int i=lon;i>=1;i--){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
