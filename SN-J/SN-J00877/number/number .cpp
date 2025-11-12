#include<bits/stdc++.h>
using namespace std;
char zi[1000005];
void p(){
	char x;
	for(int i=0;i<1000000;i++){
		if(i!=0){
			if(zi[i]>zi[i-1]){
				x=zi[i-1];
				zi[i-1]=zi[i];
				zi[i]=x;
			}
		}
	}
}
string s;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	//包含至少一个1～9中的数字
	cin>>s;
	int g=0;
	for(int i=0;i<1000000;i++){
		if('0'<=s[i]&&s[i]<='9'){
			zi[g]=s[i];
			g++;
		}
		else{
			if('a'<=s[i]&&s[i]<='z'){
			}else{
				break;
			}
		}
	}
	p();
	for(int i=0;i<1000000;i++){
		if(zi[i]<='9'&&'0'<=zi[i]){
			cout<<zi[i];
		}else{
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
