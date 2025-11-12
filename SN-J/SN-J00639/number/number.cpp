#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100011];
	int a[10001],i=1,j=1;
    while(cin>>s[i]){
    	if(s[i]>=97&&s[i]<=122){
    		s[i]='0';
		}else {
			a[j]=s[i]-'0';
			j++;
		}
		i++;
		if(s[i]=='\0')break;
	}
	sort(a+1,a+i+1);
	for(int k=j;k>1;k--){
		cout<<a[k];
	}
	return 0;
}
