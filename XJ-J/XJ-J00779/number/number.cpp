#include<bits\stdc++.h>
using namespace std;
char s[1000000];
int h[100000];
int cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++){
		if(s[i]==0) 
		{
			cnt=i;
			break;
		}
	}
	for(int l=0;l<=cnt-1;l++) {
		cout<<s[l];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
