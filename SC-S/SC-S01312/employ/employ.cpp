#include<bis/stdc++.h>
using namespace std;
typedef long long lint;

int n,m,c[550],d[550];
int hards=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	char op; cin>>n>>m;
	for(int 1=1;i<=n;i++){
		cin>>op;
		d[i]=(op=='0'?0:1);
		hards+=d[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
		
	}
	
	if(m==n&&hards){
		cout<<0;
		return 0;
	}
	
	
	return 0;
}