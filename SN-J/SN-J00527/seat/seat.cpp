#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int chu(int x,int y){
	if(x%y==0){
		return x/y;
	}
	else{
		return x/y+1;
	}
}
int n,m;
int a[200];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
		num=a[1];
		sort(a+1,a+n*m+1,cmp);
		int cc;
		for(int i=1;i<=n*m;i++){
			if(a[i]==num){
				cc=i;
			}
		}
		int ans;
		if(chu(cc,n)%2!=0){
		if(cc%n==0){
			ans=n;
		}
		else ans=cc%n;	
		}
		else{
			if(cc%n==0){
				ans=1;
			}
			else ans=n-(cc%n)+1;
		}
        cout<<chu(cc,n)<<" "<<ans;
        return 0;
}
