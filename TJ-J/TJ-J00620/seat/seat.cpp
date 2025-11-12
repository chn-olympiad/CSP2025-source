#include<bits/stdc++.h>
using namespace std;
int a[1000],a1[15][15];
int n,m,num,j=1,sum=0;
void s(){
	if(j%2==1){
		for(int i=1;i<=n;i++){
			a1[i][j]=a[sum--];
			if(a1[i][j]==num){
				cout<<j<<" "<<i;
				return ;
			}
		}	
	}else{
		for(int i=n;i>=0;i--){
			a1[i][j]=a[sum--];
			if(a1[i][j]==num){
				cout<<j<<" "<<i;
				return ;
			}
		}	
	}
	j++;
	if(j<=m) s();
	else return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	num=a[0];
	int c=n*m;
	sort(a,a+c);
	sum=c-1;
	s();
	return 0;
} 
