#include<algorithm> 
#include<cstdio>
#include<iostream>  
#include<cstring> 
#include<algorithm>  
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000000];
	int changdu;
	char shu[1000000];
	int pinjie;
	int da=0;
	char zuizhong[1000000];
	cin>>s;
	changdu=strlen(s);
	for (int i=0;i<=changdu;i++){
		shu[i]=0;
	}
	for (int i=0;i<=changdu;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			cout<<s[i];
			shu[i]=s[i];
		}
	}
	pinjie=strlen(shu);
	cout<<pinjie;
		for (int i=0;i<=pinjie;i++){
			if((int)shu[i]>da){
				da=shu[i];
				zuizhong[i]=shu[i];
				shu[i]=0;
			}
		}
	int chang;
	chang=strlen(zuizhong);
	for (int i=1;i<=chang;i++){
		cout<<zuizhong[i];
	}
	
	return 0;
}
