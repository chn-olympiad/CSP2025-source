#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=0,num=0,n;
	cin>>n;
	if(n<3){
		cout<<0;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt+=a[i];
		}
		sort(a+1,a+n+1);
		if(cnt>a[n+1]*2) num++;
		for(int i=1;i<=n-3;i--){
			int sum=cnt;
			if(sum-a[i]>a[n]*2){
				num++;
			}
		}
		cout<<num;
	}
	return 0;
}