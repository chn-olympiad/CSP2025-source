#include<bits/stdc++.h>
using namespace std;
int a[100010][4],ans=0,flag=0,n,b[4];
void dfs(int m,int n2){
	ans+=a[m][n2];
	if(m==n){
    	if(flag<=ans) flag=ans;
		return;
	}
	for(int k=1;k<=3;k++){
		if(b[k]+1>n/2) continue;
		b[k]++;
		dfs(m+1,k);
		ans=ans-a[m+1][k];
		b[k]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	for(int i=1;i<=t;t++){
		memset(b,0,sizeof(b));
		ans=0,flag=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];	
		}
		for(int g=1;g<=3;g++){
			b[g]++;
			dfs(1,g);
			memset(b,0,sizeof(b));
			ans=0;
		}
		cout<<flag<<endl;
	}
	return 0;
}


