#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(n==1){
		for(int i=1;i<=n*m;i++){
			if(a[i]==num){
				cout<<i<<" "<<n;
				return 0;
			}
		}
	}
	else if(m==1){
		for(int i=1;i<=n*m;i++){
			if(a[i]==num){
				cout<<m<<" "<<i;
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=n*m;i++){
			if(a[i]==num){
				int lie=i/n+(i%n==0? 0:1);
				int hang;
				if(i%n==0){
					hang=(lie%2==1? n:1);
				}
				else{
					hang=(lie%2==1? i%n:n-i%n+1);
				}
				cout<<lie<<" "<<hang;
				return 0;
			}
		}
	}
	return 0;
}

