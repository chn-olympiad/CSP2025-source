#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[1000005]={};
int b[1000005]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=strlen(a),c=0;
	for(int i=0;i<n;i++){
		if('0'<=a[i]&&a[i]<='9'){
			b[c]=a[i]-'0';
			c++;
		}
	}
	sort(b,b+c);
	for(int i=c-1;i>=0;i--){
			cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
