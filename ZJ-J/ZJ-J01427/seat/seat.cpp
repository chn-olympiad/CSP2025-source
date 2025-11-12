#include<bits/stdc++.h>
using namespace std;
int n,m,len,g=1;
struct p{
	int s;
	int flag;
}r[1001000];
bool cmp(p x,p y){
	return x.s>y.s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++){
		cin>>r[i].s;
		if(i==1){
			r[i].flag=1;
		}
		else r[i].flag=0;
	}
	sort(r+1,r+len+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(r[g].flag==1){
				cout<<i<<' '<<j;
				return 0;
			} 
			g++;
		}
	}
	return 0;
}
