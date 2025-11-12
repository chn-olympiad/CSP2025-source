#include<bits/stdc++.h>
using namespace std;
char s[100010];
char a[1010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,100010);
	int n;
	for(int i=1;i<=100001;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i];
			n++;
		}
	}
	sort(a+n+1,a+1);
	for(int i=1;i<=n;i++){
		printf("%s",a[i]);
	}
	return 0;
}
