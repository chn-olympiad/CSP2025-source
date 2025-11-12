#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m,ans;
int t=0;
int a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i==1){
			ans=x;
		}
		v.push_back(x);
	}
	t=v.size()-1;
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				a[i][j]=v[t];
//				cout<<"1<<"<<a[i][j]<<endl;
				if(a[i][j]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				t--;
			}
		}else{
			for(int j=m;j>=1;j--){
				a[i][j]=v[t];
//				cout<<"2<<"<<a[i][j]<<endl;
				if(a[i][j]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				t--;
			}
		}
	}
}
