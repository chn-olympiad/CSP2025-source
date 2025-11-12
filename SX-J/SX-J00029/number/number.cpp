#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000000]={0};
	char a[10000]={0};
	char t[10000]={0};
	for(int i=0;;i++){
		cin>>s[i];
        if(s[i]-s[i-1]==s[i]){
 			cout<<s[i];
 			return 0;
		}
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){

			s[i]=s[i]*1000;
			s[i-1]=s[i-1]*100;
			s[i-2]=s[i-2]*10;
            a[i]=s[i]+s[i-1]+s[i-2]+s[i-3];

            if(a[i]<t[i]){
				swap(a,t);
				a[i]=t[i];
			}

    }cout<<t[i];
	}
	return 0;
}