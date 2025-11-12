#include<bits/stdc++.h>
using namespace std;
long long n,w,ans=0;
string a[200100][2],y,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>w;
	for(long long i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	while(w>0){
		w--;
		cin>>y>>m; 
		ans=0;
		for(long long i=1;i<=n;i++){
			string y2=y;
			long long t,t1;
			long long q=0;
			for(long long p=0;p<y2.size()&&q<a[i][0].size();p++){
				if(y2[p]==a[i][0][q]){
					q++;
					t=p;
				}else{
					q=0;
				}
			}
			if(q==a[i][0].size()){
				for(long long j=a[i][1].size()-1;j>=0;t--,j--){
					y2[t]=a[i][1][j];
				}
				if(y2==m){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
