#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
char s[1000005];
int b[1000005];
using namespace std;
int main(){
	cin>>s;
	int l=strlen(s);
	int j=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9'){
			b[j]=s[i]-'0';
			j++;
		}
	}
	sort(b,b+j);
    for(int i=1;i<=j;i++){
		cout<<b[i];
    }
	return 0;
}
 

