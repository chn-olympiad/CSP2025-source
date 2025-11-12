#include<bits/stdc++.h>
using namespace std;
int mingx,mingy,mingshu;
int weici;
int n,m;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			mingshu=a[1];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==mingshu){
			weici=n*m-i+1;
		}
	}
	mingx=weici/n;
	if(weici%n!=0)
	mingx++;
	if(mingx%2==1){
		mingy=(weici-1)%n+1;
	}else{
		mingy=n-weici%n+1;
	}
	cout<<mingx<<" "<<mingy;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
