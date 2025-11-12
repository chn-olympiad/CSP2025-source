#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],cnt,ans,w;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			w=i;
		}
	}
	ans=1;
	while(1){
		if(w-n>0){
			w-=n;
			ans++;
		}else{
			break;
		}
	}
	if(ans%2==1){
		cout<<ans<<' '<<w;
	}else{
		cout<<ans<<' '<<n-w+1;
	}
	return 0;
}
