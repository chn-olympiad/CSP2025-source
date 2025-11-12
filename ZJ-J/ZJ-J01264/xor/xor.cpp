#include<bits/stdc++.h>
using namespace std;
int x,y,m,n,i,j,a[1005][21],f[1005],k[21],q,sum,dp[1001][1001][21];
void yh(int x,int y){
	int ans[21];
	for(int i=1;i<=20;i++)
	  if(a[x][i]+dp[x+1][y][i]==1){
	    ans[i]=1;
	    dp[x][y][i]=1;
	    //cout<<x<<" "<<y<<" "<<i<<" "<<ans[i]<<endl;
	  }
	  else{
	  	ans[i]=0;
	  	dp[x][y][i]=0;
	  	//cout<<x<<" "<<y<<" "<<i<<" "<<ans[i]<<endl;
	  }
	for(int i=1;i<=20;i++){
		if(ans[i]!=k[i]){
		  return;
	    }
	}
	sum++;
	for(int i=x;i<=y;i++)
	  f[i]=1;
	//for(int i=1;i<=n;i++)
	  //cout<<dp[x][y][i]<<" "<<i<<endl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    memset(f,0,sizeof(f));
    cin>>n>>q;
    int l=1,p=q;
    while(p>0){
    	k[l]=p%2;
    	p/=2;
    	l++;
	}
    for(i=1;i<=n;i++){
    	int x,l=1;
    	cin>>x;
    	if(x==q){
    		sum++;
    		f[i]=1;
		}
        while(x>0){
        	a[i][l]=x%2;
        	x/=2;
        	l++;
		}
		for(j=1;j<=20;j++){
			dp[i][i][j]=a[i][j];
		}
	}
	for(i=2;i<=n;i++){
		int r;
		for(int l=1;l+i-1<=n;l++){
			r=l+i-1;
			if(r>n) continue;
			int flag=0;
			for(int s=l;s<=r;s++){
				if(f[s]==1) flag=1; 
			}
			//cout<<l<<" "<<r<<endl<<endl;
			if(flag==0) yh(l,r);
		}
		//cout<<i<<endl;
	}
	cout<<sum;
	return 0;
}
