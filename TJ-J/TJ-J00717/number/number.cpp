#include<bits/stdc++.h>
using namespace std;
char s[100005] = {};
long long a[100005],shuwei=0;
bool b[100005];
int max1=0;
long long c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=1;i<=100005;i++){
		cin>>s[i];
		b[i] = true;
	}
	
	for(int i=1;i<=100005;i++){
		if(s[i]<='9' && s[i]>='1'){
			a[i] = s[i];
			shuwei++;
		}
	}
	
	for(int i=1;i<=shuwei;i++){
		if(shuwei-i==0){
			c += a[i];
			break;
		}
		for(int j=1;j<=shuwei;j++){
			if(a[j]>=max1 && b[j]==true){
				max1 = a[j];
			}
		}
		for(int j=1;j<=shuwei-i+1;j++){
			a[i] *= 10;
			if(j==shuwei-i+1){
				c+=a[i];
				b[i] = false;
			}
		}
	}
	printf("%lld",c);
	return 0;
}
