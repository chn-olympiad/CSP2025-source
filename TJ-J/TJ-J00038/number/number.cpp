#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	char a[1000000];
	char b[1000000];
	cin>>a;
	int n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=int(a[i]);
		}
	}
	for(int i=0;i<=n-1;i++){
		for(int j=1;j<=n-1;j++){
			if(b[j-1]<b[j])
				swap(b[j-1],b[j]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
