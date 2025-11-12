#include <iostream>
#include <string>
using namespace std;
string s;
int a[10];
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]&&i!=0){
			flag=true;
			for(int j=1;j<=a[i];j++){
				printf("%d",i);
			}
		}
		else if(i==0){
			if(!flag){
				printf("0");
			}
			else{
				for(int j=1;j<=a[0];j++){
					printf("0");
				}
			}
		}
	}
	return 0;
}
