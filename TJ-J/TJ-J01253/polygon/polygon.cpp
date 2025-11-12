#include<iostream>
#include<cmath>
using namespace std;
int n;
int a[10005][10005],b[10005][10005];
int num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=a[i][i];
			for(int q=i+1;q<=j;q++){
				ans+=a[q][q];
			}
			a[i][j]=ans;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ans=a[i][i];
			for(int q=i+1;q<=j;q++){
				ans=max(ans,a[q][q]);
			}
			b[i][j]=ans;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i][j]>b[i][j]*2){
				num++;
			}
				
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
