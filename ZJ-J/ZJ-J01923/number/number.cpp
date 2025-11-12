#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n[10],a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9')n[a[i]-'0']+=a[i];
	}
	for(int i=9;i>=0;i--)
		cout<<n[i];
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
