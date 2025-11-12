#include <bits/stdc++.h>
using namespace std;
string s[100010];
int sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	//cin>>s;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		sum1=sum1+s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i]<='0'&&s[i]>='9'){
				cout<<s[i];
				}
			}
		}
	for(int i=1;i<=n;i++){
		cout<<s[i];
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}





/*
290es1q0
1,È¥×ÖÄ¸£¬ÁôÏÂ¡¢Êý×Ö:2 9 0 1 0

2£¬ÅÅÐò£¬×ÖµäÐò£¬´Ó´óµ½Ð¡£º92100



1.ÊäÈë×Ö·û´®s Êä³ö 

*/
