#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
long long n[N],p;
char a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]<='9'&&a[i]>=0){
			n[p]=a[i];
			p++;
		}
	}
	for(int i=p-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(n[j]-'0'>n[j+1]-'0')
			swap(n[j],n[j+1]);
		}
	}
	for(int i=p-1;i>=0;i--){
		n[i]-='0';
		printf("%lld",n[i]);
	}
	return 0;
}
