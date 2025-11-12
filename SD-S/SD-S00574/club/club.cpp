#include<bits/stdc++.h>
using namespace std;
int aone[100005],atwo[100005],atr[100005],dp[3][100005],a[3][100005]; 
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout); 
	int t,n,f2=0,f3=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>aone[i]>>atwo[i]>>atr[i];
			if(atwo[i]!=0){
				f2=1;
			}if(atr[i]!=0){
				f3=1;
			}
		}for(int i=1;i<=n;i++){
			a[1][i]=aone[i];
			a[2][i]=atwo[i];
			a[3][i]=atr[i];
		}
		for(int i=n;i>=2;i--){
				for(int j=1;j<=i;j++){
					if(aone[j]>aone[j+1]){
						swap(aone[j],aone[j+1]);
					}
			}
		}
		for(int i=n;i>=2;i--){
				for(int j=1;j<=i;j++){
					if(atwo[j]>atwo[j+1]){
						swap(atwo[j],atwo[j+1]);
					}
				}
		}
		for(int i=n;i>=2;i--){
				for(int j=1;j<=i;j++){
					if(atr[j]>atr[j+1]){
						swap(atr[j],atr[j+1]);
					}
				}
		}
		if(f2==0&&f3==0){
			int cnt1=0;
			for(int i=n;i>=n-n/2;i--){
				cnt1+=aone[i];
			}
			cout<<cnt1<<endl;
			return 0;
		}
		if(f3==0){
			int cnt1=0;
			for(int i=n;i>=n-n/2;i--){
				cnt1+=aone[i]+atwo[i];
			}
			cout<<cnt1<<endl;
			return 0;
		}
		
		dp[1][1]=aone[1];
		dp[2][1]=atwo[1];
		dp[3][1]=atr[1];
		for(int i=2;i<=n;i++){
			dp[1][i]=aone[i]+dp[1][i-1];
		}
	}
	return 0;
}

