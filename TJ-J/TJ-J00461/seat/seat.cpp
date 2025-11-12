#include<bits/stdc++.h>
using namespace std;
int m,n,ans[100],sum[100][100],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>ans[i];
		if(i==0){
			r=ans[i];
		}
	}
	sort(ans,ans+m*n);
	int tmp=m*n-1;
	//±éÀú 
	int num=1;
	for(int i=1;i<=n;i++){
		sum[i][num]=ans[tmp];	
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	for(int i=n;i>=1;i--){
		sum[i][num]=ans[tmp];		
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	//
	for(int i=1;i<=n;i++){
		sum[i][num]=ans[tmp];	
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	for(int i=n;i>=1;i--){
		sum[i][num]=ans[tmp];		
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	//
	for(int i=1;i<=n;i++){
		sum[i][num]=ans[tmp];	
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	for(int i=n;i>=1;i--){
		sum[i][num]=ans[tmp];		
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	for(int i=1;i<=n;i++){
		sum[i][num]=ans[tmp];	
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	for(int i=n;i>=1;i--){
		sum[i][num]=ans[tmp];		
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	for(int i=1;i<=n;i++){
		sum[i][num]=ans[tmp];	
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	num++;
	for(int i=n;i>=1;i--){
		sum[i][num]=ans[tmp];		
		if(ans[tmp]==r){
			cout<<num<<" "<<i;
			return 0;
		}
		tmp--;
	}
	return 0; 
} 
//#Shang4Shan3Ruo6Shui4 
