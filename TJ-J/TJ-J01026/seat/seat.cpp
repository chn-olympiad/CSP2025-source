#include<bits/stdc++.h> 
using namespace std;
int xx[20][20];
int s[401];
bool cmp(long long a,long long b){
	if(a>b){
		return 1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int v=n*m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	int r=s[0];
	sort(s,s+v,cmp);
	int cnt=0;
	int l=0;
	
	for(int i=1;i<=m;i++){
		if(l!=0) l-=2;
		
		if(l==0){
			
			for(int j=1;j<=n;j++){
				xx[i][j]=s[cnt];
				cnt++;
				
			}
			l=1;
		}
		if(l==1){
			
			for(int j=n;j<0;j++){
				xx[i][j]=s[cnt];
				cnt++;
				
			}
			l=2;
		}
		
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(xx[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			}

		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
