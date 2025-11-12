#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[999999],u=0,n=0,j=0,t=0;
	char s[999999],d[9999];
    gets(s);
        while(s[u] != '\0'){
		if(s[u]>='0'&&s[u]<='9'){
		a[j]=s[u];
		j++;
		}else{
			d[n]=s[u];	n++; 
		}

	u++;
	}
        for(int i=0;i<j-1;i++){
		for(int q=0;q<j-1;q++){
		if(a[q]<a[q+1]){
			t=a[q];
			a[q]=a[q+1];
		a[q+1]=t;
		}		
		}
		j++;
	}
	n=0;
while(a[n]!='\0'){
   	    a[n]=a[n]-'0';
    	cout<<a[n];
    n++;
	}
	return 0;
}
