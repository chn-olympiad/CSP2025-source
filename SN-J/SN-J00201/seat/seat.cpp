#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xiaoa=a[1];
	sort(a+1,a+n*m+1,cmp);
	int xiaoai=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaoa){
			xiaoai=i;
			break;
		}
	}
	int i=1;
	while(xiaoai>n){
		i++;
		xiaoai-=n;
		
	}
	if(i%2==1){
		cout<<i<<" "<<xiaoai;
	}
	else cout<<i<<" "<<m-xiaoai+1;
}
