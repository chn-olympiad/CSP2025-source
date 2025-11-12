//考号：SN-J00509 姓名：李兴辰 学校：安康高新技术产业开发区九年制学校
#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
bool a[105];
void read(){
	cin>>n>>m;
	int t;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		a[x]=1;
		if(i==1)t=x;
	}
	for(int i=100;i;i--){
		if(i==t)break;
		if(a[i]){
			k++;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	read();//get(k);
	int l=(k-1)/n+1;
	cout<<l<<' ';
	if(l&1){
		cout<<(k-1)%n+1;
	}else{
		cout<<n-(k-1)%n;
	}
	return 0;
} 
