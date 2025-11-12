#include<bits/stdc++.h>
using namespace std;

int a[20];
int ans[20][20];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	int l=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]!=r){
			l++;
		}
		else{
			break;
		}
	}
	int h;
	if(l%n==0){
		h=l/n;
	}
	else{
		h=l/n+1;
	}
	int lie=l%n;
	cout<<h<<" ";
	if(h%2==0){
		if(lie==0){
			cout<<"1";
		}
		else{
			cout<<m-lie+1;
		}
	}
	else{
		if(lie==0){
			cout<<m;
		}
		else{
			cout<<lie;
		}
	}
	return 0;
}
