#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number3.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000001]={};
	long long a[100010]={},ans=0;
	cin>>s;
	for(long long i=0;i<=strlen(s)-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	for(long long i=ans-1;i>=0;i--){
		for(long long j=0;j<=i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(long long i=0;i<=ans-1;i++){
		cout<<a[i];
	}
	return 0;
}
