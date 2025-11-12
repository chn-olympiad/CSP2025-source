#include<bits/stdc++.h>
using namespace std;
long long t,n,k[100010][5],c=0,b=0,a[100010],ans=0,m,r,sum=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>k[i][1]>>k[i][2]>>k[i][3];
			if(k[i][2]!=0){
				b=1;
			}
			if(k[i][3]!=0){
				c=1;
			}
			a[i]=k[i][1];
			sum+=max(max(k[i][1],k[i][2]),k[i][3]);
		}
		if(b==0&&c==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans;
		}else{
			if(n==2){
				ans=max(max(k[1][1],k[1][2]),k[1][3]);
				for(int j=1;j<=3;j++){
					if(k[1][j]==ans){
						m=k[2][j];
						r=j;
						k[2][j]=0;
						break;
					}
				}
				int ans2=max(max(k[2][1],k[2][2]),k[2][3]);
				int ans3=ans+ans2;
				k[2][r]=m;
				int ans4=max(max(k[2][1],k[2][2]),k[2][3]);
				for(int j=1;j<=3;j++){
					if(k[2][j]==ans){
						m=k[1][j];
						r=j;
						k[1][j]=0;
						break;
					}
				}
				int ans5=max(max(k[1][1],k[1][2]),k[1][3]);
				int ans6=ans4+ans5;
				int ans7=max(ans6,ans3);
				cout<<ans7;
			}else{
				cout<<sum;
			}
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
