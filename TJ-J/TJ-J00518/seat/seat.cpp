#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	int h=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==h){
			int x=(i+n-1)/n;
			if(x%2==1){
				if(i%n==0){
					cout<<x<<" "<<n;
				}
				else{
					cout<<x<<" "<<i%n;
				}
			}
			else{
				cout<<x<<" "<<(x*n+1)%n+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
