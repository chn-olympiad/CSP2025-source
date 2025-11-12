//SN-J00910   芦思辰      高新第一学校
#include<bits/stdc++.h>
using namespace std;
int main(){
//	fropen("number.in","r",stdin);
//	fropen("number.out","w"stdiut);
	char s[100005];
	for(int i=0;i<=10005;i++){
		cin >> s[i];
	for(int i=1;i<=s[i];i++){
	if(s[1]>=1 && s[1]<=9){
	cout << s[1];
			}
		}
	}
	
	
	for(int i=1;i<=s[i];i++){
		if(s[i]>=1 && s[i]<=9){
			if(s[i+1]>=1 && s[i]<=9){
				if(s[i]>s[i+1]){
					cout <<s[i] <<s[i+1];
				}
			}
			else{
				cout << s[i+1] <<s[i];
			}
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
