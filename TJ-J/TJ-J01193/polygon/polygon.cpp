#include<bits/stdc++.h>
/*fjx 20120225 rp++*/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAX=1e7+5;
const ll N=998244353;
int a[5005];
int jie(int x){
	int sum=1;
	for(int i=1;i<=x;i++){
		sum*=i;
	}
	return sum;
}
int c(int a,int b){
	int sum=1;
	for(int i=1;i<=b;i++){
		sum*=a;
		a--;
	}
	return sum/jie(b);
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int maxx=-1;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=3){//12fen
		int sum=0;
		if(maxx*2<s){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
//	if(maxx<=100&&n<=10){
//		for(int i=3;i<=n;i++){
//			
//		}
//		return 0;
//	}
	if(maxx==1){
		ull sum=0;
		for(int i=3;i<=n;i++){
			sum+=c(n,i);
		}
		cout<<sum;
		return 0;
	}
	cout<<n; 
	return 0;
} 
/*
password:#Shang4Shan3Ruo6Shui4
*/
