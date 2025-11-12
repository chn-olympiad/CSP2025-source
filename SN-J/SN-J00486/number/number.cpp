#include<bits/stdc++.h>

using namespace std;
char s[1000000];
int r[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]<='9'&&s[i]>='0'){
			r[len]=s[i]-48;
			len++;
		}
	}
	for(int i=0;i<len-1;i++){
		for(int j=i;j<len;j++){
			if(r[j]<r[j+1]){
				int e=r[j];
				r[j]=r[j+1];
				r[j+1]=e;
			}
		}
	}
	for(int i=0;i<len;i++){
		cout<<r[i];
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
