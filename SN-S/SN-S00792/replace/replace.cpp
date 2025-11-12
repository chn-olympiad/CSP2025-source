#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	while(q--){
		string a[200005][2];
		for(int i=1;i<=n/2+1;i++){
			for(int j=1;j<=2;j++){
				cin>>a[i][j];
			}
		}
		int minn=INT_MAX;
		for(int i=2;i<=n/2+1;i++){
			int len=a[i][1].size();
			minn=min(minn,len);
		}
		if(minn>a[1][1].size()){
			cout<<0;
		}else{
			cout<<abs(n-q);
		}
	} 
	fclose(stdin);
	fclose(stdout);
} 
