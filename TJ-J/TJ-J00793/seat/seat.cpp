#include <bits/stdc++.h>
using namespace std;
long long n,m,a[20][20],cnt,ab[125];
bool cmp1(int a,int b){
	return a>b;
}
int h(int a){
	if(a%n==0){
		return a/n;
	}
	else{
		return a/n+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ab[i];
	}
	cnt=ab[1];
	sort(ab+1,ab+1+n*m,cmp1);
	for(int i=1;i<=n*m;i++){
		if(h(i)%2==0){
			if(i%n==0){
				a[h(i)][1]=ab[i];
			}
			else{
				a[h(i)][i%n+1]=ab[i];
			}
		}
		else{
			if(i%n==0){
				a[h(i)][n]=ab[i];
			}
			else{
				a[h(i)][i%n]=ab[i];
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==cnt){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
