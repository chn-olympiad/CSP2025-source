#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	int n=0;
	cin>>a;
	while(a[n]>='a'&&a[n]<='z'||a[n]>='0'&&a[n]<='9')n++;
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if('0'<=a[i]&&a[i]<='9'){
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
