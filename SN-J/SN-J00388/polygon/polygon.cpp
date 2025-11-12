#include<bits/stdc++.h>
using namespace std; 
int n,a[5005],ans;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(a[1]+a[2]+a[3]>a[1]*2){
		ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
