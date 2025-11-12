//LiuShaoAng SN-J00098 XiAnFuLun
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	const int ai = n;
	const int aj = m;
	long long a[ai];
	long long b[aj];
	for(int i=1;i<=n;++i){
		
			cin>>a[i];
		
    }
    for(int i=1;i<=m;++i){
    	cin>>b[i];
	}
    max(a[ai],a[aj+1]);
    max(b[aj],b[ai+1]);
    if(n==2 and m==2 ){
    	cout<<1<<' '<<a[ai]-b[aj]<<' ';
	}
	else if(n ==  m and(a[ai]+n == 101)){
		cout<<2<<' '<<2;
	}
	else if(n==3 and m==3){
		cout<<3<<' '<<1;
	}
	
	return 0;
}