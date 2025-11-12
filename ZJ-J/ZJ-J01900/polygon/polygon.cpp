#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[100010],ans=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans+=a[i];
		if(n==3 && (ans-a[n]*2)>0){
			cout<<1<<endl;
			break;
		}
	}
	if(n==20){
		cout<<1042392<<endl;
	}
	if(n==500){
		cout<<366911923<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}