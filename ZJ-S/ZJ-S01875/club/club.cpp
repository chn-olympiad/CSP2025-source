#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
long long s,r[5],n,a[N][3],ans;
void search(int i,long long s,long long r[]){
	if(i==n+1){
		ans=max(ans,s);
		return;
	}
	bool f=false;
	for(int j=1;j<=3;j++){
		if(r[j]<(n/2)){
			f=true;
			r[j]++;
			s+=a[i][j];
			search(i+1,s,r);
			r[j]--;
			s-=a[i][j];
		}
	}
	if(f==false)return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
			cin>>n;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
			}
			s=0;
			memset(r,0,sizeof(r));
			search(1,s,r);
			cout<<ans<<endl;
			ans=0;
	}
	return 0;
}