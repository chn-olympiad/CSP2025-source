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
	cin>>n>>m;//n hang ,m lie
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;
	for(int i=2;i<=n*m;i++){
		if(c%2==1){
			if(r==n) c++;
			else r++;
		}else{
			if(r==1) c++;
			else r--;
		}
		if(a[i]==num){
			cout<<c<<' '<<r;
			break;
		}
	}
	return 0;
}
