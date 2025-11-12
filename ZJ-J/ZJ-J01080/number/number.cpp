#include<bits/stdc++.h>

using namespace std;
int a[10];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    string n;
    cin>>n;
	int i=0;
	while(n[i]!='\0'){
		if(n[i]-'0'<=9&&n[i]-'0'>=0){
			a[n[i]-'0']++;
		}i++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
fclose(stdin);
fclose(stdout);
    return 0;
}
