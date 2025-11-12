#include <bits/stdc++.h>
using namespace std;
const int MAXN=205;
struct node{
	int id,poi;
}a[MAXN];
bool cmp(node a,node b){
	return a.poi>b.poi;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].poi;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int flag=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			flag=i;
			break;
		}
	}
	if(flag%n==0){
		cout<<flag/n<<" ";
		if(flag/n%2==0){
			cout<<"1";
		}else{
			cout<<n;
		}
		return 0;
	}
	if((flag/n+1)%2==0){
		cout<<(flag/n+1)<<" "<<n-flag%n+1;
	}else{
		cout<<(flag/n+1)<<" "<<flag%n;
	}
	return 0;
}