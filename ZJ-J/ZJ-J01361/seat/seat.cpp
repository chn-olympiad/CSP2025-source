#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[105],cnt,ax,ay;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	cnt=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(cnt==a[i]){
			ax=i/n;
			if(i%n!=0){
				ax++;
				if(ax%2==0){
					ay=n-i%n+1;
				}else{
					ay=i%n;
				}
			}else{
				if(ax%2==0){
					ay=1;
				}else{
					ay=n;
				}
			}
			break;
		}
	}
	cout<<ax<<" "<<ay;
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/