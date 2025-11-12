#include <bits/stdc++.h>
using namespace std;
string s;
char shu[1000005];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			shu[cnt]=s[i];
			cnt++;
		} 
	}
	int len1=strlen(shu);
	sort(shu,shu+len1,cmp);
	for(int i=0;i<len1;i++){
		cout<<shu[i];
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

























 
