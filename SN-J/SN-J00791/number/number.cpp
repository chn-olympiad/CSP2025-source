#include<bits/stdc++.h>
using namespace std;
char a[1000005];
char b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char max='0',min='9';
	for(int i=1;i<=1000005;i++){
		cin>>a[i];
		if('0'<=a[i]&&a[i]<='9'){
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
