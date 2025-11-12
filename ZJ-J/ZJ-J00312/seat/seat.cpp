#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
struct node{
	int x,y;
} z[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	int na=a[1];
	sort(a+1,a+1+nm,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			int k=1;
			for(int j=(i-1)*n+1;j<=i*n;j++){
				z[j].x=k;
				z[j].y=i;
				k++;
			}
		}else{
			int k=n;
			for(int j=(i-1)*n+1;j<=i*n;j++){
				z[j].x=k;
				z[j].y=i;
				k--;
			}
		}
	}
	for(int i=1;i<=nm;i++){
		if(a[i]==na){
			cout<<z[i].y<<" "<<z[i].x;
			break;
		}
	}
	return 0;
}
