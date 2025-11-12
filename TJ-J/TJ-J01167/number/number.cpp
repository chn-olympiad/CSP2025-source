#include<bits/stdc++.h>
using namespace std;
 
short a[1000005];
char s[1000005];
int shu;
//bool ok;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu++;
			a[shu]=s[i]-'0';
		}
	}
	sort(a+1,a+shu+1);
	
	if(a[shu]==0){
		cout<<0;		
	}else{
		for(int i=shu;i>=1;i--){
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
