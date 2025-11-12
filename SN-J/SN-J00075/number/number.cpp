#include <bits/stdc++.h>
using namespace std;
char a[10000008];
int n[10000001],num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			num++;
			n[num]=a[i]-'0';
			
		}
	}
	sort(n+1,n+1+num);
	
	for(int i=num;i>=1;i--){
		cout<<n[i];
	}
	
	return 0;
}

