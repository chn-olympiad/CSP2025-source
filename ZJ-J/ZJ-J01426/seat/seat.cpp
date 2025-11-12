#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],f,cnt,ansn,ansm;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		cnt++;
		if(a[i]==f) break;
	}
	ansn=int(ceil(1.0*cnt/m));
	if(ansn%2==1){
		if(cnt%m==0) cout<<ansn<<' '<<m;
		else cout<<ansn<<' '<<cnt%m; 
	}
	else{
		if(cnt%m==0) cout<<ansn<<' '<<1;
		else cout<<ansn<<' '<<m-cnt%m+1;
	}
	return 0;
}
