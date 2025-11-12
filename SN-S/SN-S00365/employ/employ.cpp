#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,num=1,b=0;
	int a[501]={0};
	string s1;
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			b++;
		}
	}
	n-=b;
	for(int i=n;i>=1;i--){
		num=num*i%998244353;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
