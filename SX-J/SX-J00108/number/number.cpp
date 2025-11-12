#include<bits/stdc++.h>
using namespace std;
char n[100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long s,cnt=0;

	cin>>n;
	s=sizeof(n);

	int a[s+5];
	for(int i=0;i<s;i++){

		if(int(n[i])>=48&&int(n[i])<=57){
			a[cnt]=n[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,greater<int>());
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}