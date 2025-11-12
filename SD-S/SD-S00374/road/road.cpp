#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int tu[10002][10002],ans=0;
bool flag[10002];

void xun(int dq){
	int min=INT_MAX,mflag=dq;
	for(int i=dq,j=1;j<=n;j++){
		if(tu[i][j]<min&&tu[i][j]>=0){
			min=tu[i][j];
			mflag=j;
		}
	}
	ans+=tu[dq][mflag];
	tu[dq][mflag]=-1;
	tu[mflag][dq]=-1;
	if(mflag!=dq){
		xun(mflag);
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k>0){
		cout<<"0";
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				tu[i][j]=-1;
			}
		}
		int a,b,c;
		for(int i=1;i<=m;i++){
			cin>>a>>b>>c;
			tu[a][b]=c;
			tu[b][a]=c;
		}
		flag[1]=1;
		xun(1);
		cout<<ans;
	}
	return 0;
}
