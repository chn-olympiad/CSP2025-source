#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int R=0;
int pm=0;
bool cmp(int x,int y){
	return x>y;
}
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			pm=i;
			break;
		}
	}
	cout<<(pm+m-1)/m<<' ';
	if(((pm+m-1)/m)%2==0){
		if(pm%m!=0){
			pm%=m;
		}
		pm%=m;
		int j=m+1;
		while(pm--){
			j--;
		}
		cout<<j<<'\n';
	}else{
		if(pm%m!=0){
			pm%=m;
		}
		int j=0;
		while(pm--){
			j++;
		}
		cout<<j<<'\n';
	}
	return 0;
}