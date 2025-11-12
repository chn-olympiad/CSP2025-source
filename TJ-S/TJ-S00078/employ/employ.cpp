#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,s,c;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=n;j++){
			cin>>c;
		}
		if(s==1&&s<c){
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
}
