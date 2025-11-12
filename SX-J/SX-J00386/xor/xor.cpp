#include<bits/stdc++.h>
using namespace std;
int t[100];
int a[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>t[i];
	}
	int b=t[1],cnt=1;
	bool flag=1;
    sort(t+1,t+1+n*m,cmp);
    for(int i=1;i<=n;i++){
    	if(flag==1){
           for(int j=1;j<=m;j++){
           a[j][i]=t[cnt++];
		   }
		   flag=0;
		   continue;
		}
		if(flag==0){
           for(int j=m;j>=1;j--){
           a[j][i]=t[cnt++];
		   }
		   flag=1;
		   continue;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==b) cout<<j<<" "<<i;
		}
	}
	return 0;
}