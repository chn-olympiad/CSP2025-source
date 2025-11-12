#include<bits/stdc++.h>
using namespace std;
int a[25];
int n,ans=0;
int chosen[25]={0};
void find(int last,int rest,int length){
	if(rest==0){
		if(chosen[length]<2*chosen[length-1]){
			ans++;
			return;
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		chosen[length-rest+1]=chosen[length-rest]+a[i];
		find(i,rest-1,length);
		chosen[length-rest+1]-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		find(0,i,i);
	}
	cout<<ans;
	return 0;
}
