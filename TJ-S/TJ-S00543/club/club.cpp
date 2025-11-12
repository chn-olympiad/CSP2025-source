# include<bits/stdc++.h>
using namespace std;
int t,n,ma,sum=0;
int a[100][100],b[100100],c[100100];
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>b[i];
			cin>>a[i][2]>>a[i][3];
		}
		for(int i=n;i>=n*0.5;i--){
			sum+=b[i];
		}
		cout<<sum;
	}
	return 0;
}
