#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	int n,m;
	int fs,pm;
	cin >> n >> m;
	int a[104];
	for(int i=0;i<n*m;i++){
		cin >> a[i];
		if(i==0){
			fs=a[i];
		}
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==fs){
			pm=i+1;
		}
	}
	if((pm/n+1)%2==0){
		cout <<pm/n+1 << n-(pm%n)+1;
	}else{
		cout <<pm/n+1 << pm%n;
	}
	return 0;
}

