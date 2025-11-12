#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
int a[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
	sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
	}else if(n<=3){
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
	}else{
		cout<<9;
	}
	return 0;
}
