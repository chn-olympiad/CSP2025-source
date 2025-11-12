#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum) cnt=i;
	}
	if(cnt<=n){
		cout<<1<<" "<<cnt;
		return 0;
	}else{
		if(cnt%n==0){
			cout<<cnt/n<<" "<<n;
			return 0;
		}else{
			cout<<(cnt/n)+1<<" "<<cnt-(cnt/n)*n;
			return 0;
		}
	}
}
