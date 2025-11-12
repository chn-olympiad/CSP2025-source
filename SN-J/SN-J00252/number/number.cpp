#include<bits/stdc++.h>
using namespace std;
char a[1000001],b[1000001];
int i=1,cnt=1;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>a;
	for(int i=0;i<=strlen(a);i++){
		if(isdigit(a[i])){
			b[cnt]=a[i];
			cnt++;
			}
	}
	for(int j=1;j<=cnt-2;j++){
		for(int k=j+1;k<=cnt-1;k++){
			if(b[j]<b[k]){
				swap(b[j],b[k]);
			}
		}
	}
	for(int j=1;j<=cnt-1;j++){
		cout<<b[j];
	}
	return 0;
}
