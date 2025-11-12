#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	int target=a[1];
	sort(a+1,a+1+cnt,cmp);
	int pos=0;
	for(int i=1;i<=cnt;i++){
		if(a[i]==target){
			pos=i;
			break;
		}
	} 
	
	int lie=pos/n;
	int hang=pos%n;
	cout<<lie+1<<" ";
	if(lie%2==1){
		cout<<n-hang+1;
	}
	else{
		cout<<hang;
	}
	return 0;
}
