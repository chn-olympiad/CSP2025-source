#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int num[1000005],t;
bool cmp(int x,int y){
	return(x > y);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < strlen(s);i++){
		if(s[i] >= '0' && s[i] <= '9') num[++t] = s[i]-'0';
	}
	sort(num+1,num+t+1,cmp);
	for(int i = 1;i <= t;i++) cout << num[i];
	return 0;
}
