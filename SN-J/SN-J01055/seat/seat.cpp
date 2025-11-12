#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,gd[10100];
bool cmp(int a,int b){return a>b;}
int find(int x){
	for(int i=1;i<=n*m;i++){
		if(gd[i]==x){
			return i;
		}
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>gd[i];
	t=gd[1];
	sort(gd+1,gd+n*m+1,cmp);
	int id=find(t);
	int l=id/n+(id%n!=0);
	int h=id%n;
	if(h==0)h=id;
	bool k=l%2;
	if(k==1){
		cout<<l<<" "<<h;
	}else{
		cout<<l<<" "<<n-h+1;
	}
	return 0;
}

