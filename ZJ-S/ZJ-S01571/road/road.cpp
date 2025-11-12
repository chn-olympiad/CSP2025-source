#include <bits/stdc++.h>

using namespace std;

int a[100005],b[100005],c[100005];
int v[10005][10005];

struct Node{
	int xuhao;
	int feiyong;
}s[10005];

bool paixu(Node x,Node y){
	if(x.feiyong<y.feiyong){
		return true;
	}else if(x.feiyong==y.feiyong&&x.xuhao<y.xuhao){
		return true;
	}
	return false;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	} 
	sort(c+1,c+1+m);
	int c2=1;
	long long ans=0;
	while(c2<=k){
		ans+=c[c2];
		c2++;
	}
	for(int i=1;i<=k;i++){
		cin>>s[i].feiyong;
		s[i].xuhao=i;
		for(int j=1;j<=m;j++){
			cin>>v[i][j];
		}
	}
	sort(s+1,s+1+k,paixu);
	int minn=s[1].xuhao;
	ans+=s[1].feiyong;
	sort(v[minn]+1,v[minn]+1+m);
	c2=1;
	while(c2<=k){
		ans+=v[minn][c2];
		c2++;
	}
	cout<<ans;	
		
	return 0;
}
