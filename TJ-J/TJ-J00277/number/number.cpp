#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin)
	//freopen("number.out","w",stdout)
	char s[100];
	cin>>s;
	char d[100];
	int c=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			d[c]=s[i];
			c++;
		}
		d[c]='\0';
		for(int i=0;i<c-1;i++){
			for(int j=0;j<c-1-i;j++){
				if(d[j]<d[j+1]){
				char t=d[j];
				d[j]=d[j+1];
				d[j+1]=t;
			}
		}
	}
}
	cout<<d<<endl;
	return 0;
}
