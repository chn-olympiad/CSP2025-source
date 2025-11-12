#include<bits/stdc++.h>
using namespace std;

int t,n;
int arr[200200][5];
int brr[1020][1020];
int ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
		}
		int N=n/2;
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++){
				brr[i][j]=0;
			}
		}
		
		for(int k=1;k<=n;k++){
			for(int i=N;i>=0;i--){ 
				for(int j=N;j>=0;j--){ 
					if(k-i-j>0 && k-i-j<N) brr[i][j]=max(brr[i][j],brr[i][j]+arr[k][3]);
					if(i>0) brr[i][j]=max(brr[i][j],brr[i-1][j]+arr[k][1]);
					if(j>0) brr[i][j]=max(brr[i][j],brr[i][j-1]+arr[k][2]);
					
				}
			}
			
		}
	/*	cout<<endl;
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++){
				cout<<brr[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;	
		
	*/	
		ans=0;
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++){
				ans=max(ans,brr[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
