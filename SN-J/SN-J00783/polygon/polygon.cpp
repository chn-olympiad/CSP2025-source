#include<bits/stdc++.h>
using namespace std;
int n,cnt,zhong;
int a[105];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		zhong+=i;
	}
	cout<<zhong;
	return 0;
}
