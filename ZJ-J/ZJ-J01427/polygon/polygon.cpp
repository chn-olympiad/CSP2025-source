#include<bits/stdc++.h>
using namespace std;
int n,k[1001000],v[1001000];
long long ans;
int s[1001000];
void jj(int edge,int deep,int u){
	if(deep==edge+1) {
		return ;
	}
	for(int i=u;i<=n;i++){
		s[deep]=i;
		int cnt=1;
		if(deep==edge){
			int maxx=0;
			long long man8=0;
			for(int j=1;j<=edge;j++){
				man8+=k[s[j]];
				maxx=max(maxx,k[s[j]]);
				if(v[s[j]]==0) cnt=0;
			}
			if(man8>(maxx*2)&&cnt==0){
				for(int j=1;j<=edge;j++){
					v[s[j]]=1;
//					cout<<v[s[j]]<<"     ";
				}
				ans++;
				ans%=998244353;
			} 
//			for(int j=1;j<=deep;j++){
//				cout<<s[j]<<' ';
//			}		
//			cout<<"     "<<cnt;
//			cout<<endl;		
		}
		jj(edge,deep+1,i+1);
	}
	v[deep]=0;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
	}
	for(int i=3;i<=n;i++){
		jj(i,1,1);
		for(int j=1;j<=n;j++){
			v[j]=0;
		}
	}
	cout<<ans;
	return 0;
}
