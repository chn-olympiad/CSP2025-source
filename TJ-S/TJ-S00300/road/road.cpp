#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		int sum=0;
		for(int i=1;i<=m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			sum+=c;
		}
		cout<<sum;
	}else{
		int sum=0;
		for(int i=1;i<=m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(sum>c)sum+=c;
		}
		for(int i=1;i<=k;i++){
			int a;
			cin>>a;
			for(int j=1;j<n;j++){
				int b[n+3];
				cin>>b[j];
				sum+=b[j];
			}
		}
		cout<<sum;
	}
	return 0;
}
