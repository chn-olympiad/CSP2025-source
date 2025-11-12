#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==cnt){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0)cout<<cnt/n<<" ",sum=cnt/n;
	else cout<<cnt/3+1<<" ",sum=cnt/n+1;
	if(sum%2==1){
		if(cnt%n==0){
			cout<<n<<" ";
		}else{
			cout<<cnt%n;
		}
	}
	else{
		if(cnt%n==0){
			cout<<1;
		}else{
			cout<<n+1-cnt%n;
		}
	}
	return 0;
}
