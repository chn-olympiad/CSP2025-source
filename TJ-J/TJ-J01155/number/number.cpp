#include<bits/stdc++.h>
using namespace std;
char s[10000005];
int a[1000005],sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a,a+sum+1);
	for(int i=sum ;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
