#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			int k;
			if(i%n==0)k=i/n;
			else k=i/n+1;
			if(k%2==1){
				if(i%n==0)cout<<k<<" "<<n;
				else cout<<k<<" "<<i%n;
			}
			else{
				if(i%n==0)cout<<k<<" "<<1;
				else cout<<k<<" "<<n-(i%n)+1;
			}
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}