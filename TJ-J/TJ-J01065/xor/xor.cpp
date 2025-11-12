#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500005];
int r[1001][1001];
bool b[500005];
bool AA=1;
int cal(int x,int y){
	int ans=a[x];
	for(int i1=x+1;i1<=y;i1++){
		ans^=a[i1];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			AA=0;
			break;
		}
	}
	if(AA&&k==0){
		if(n==1) cout<<0;
		else if(n==2) cout<<1;
		else cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			r[i][j]=cal(i,j);
			for(int k=j+1;k<=n;k++){
				for(int l=k;l<=n;l++){
					r[k][l]=cal(k,l);
				}
			}
		}
	}
	memset(b,false,sizeof(b));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cal(i,j)==k){
				for(int k=i;k<=j;k++) if(b[i]==1) continue;
				for(int k=i;k<=j;k++) b[i]=1;
				cnt++;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

