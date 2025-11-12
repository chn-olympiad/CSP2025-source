#include <bits/stdc++.h>
using namespace std;
long long num,s,n=0,a[555555];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	cin>>s;
	while(s>0){
		a[++n]=s%10;
		s/10;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		num=num*10+a[i];
	}
	cout<<num/10;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
