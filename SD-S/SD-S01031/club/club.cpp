#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int T,n,ans,a[N][5],book[N],club[5],tot1,tot2,cun[N];

void dfs(int k,int s){
	if(k>n){
		ans=max(ans,s);
	}
	for(int i=1;i<=3;i++){
		if(club[i]<n/2){
			club[i]+=1;
			dfs(k+1,s+a[k][i]);
			club[i]-=1;
		}
	}
}
bool cmp(int _,int __){
	return _>__;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;//25pts
	while(T--){
		memset(book,0,sizeof(book));
		memset(club,0,sizeof(club));
		memset(a,0,sizeof(a));ans=0;tot1=0;tot2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2&&a[i][j]!=0)tot1++;
				if(j==3&&a[i][j]!=0)tot2++;
				if(j==1)cun[i]=a[i][j];
			}
		}
		if(tot1==0&&tot2==0){
			stable_sort(cun+1,cun+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=cun[i];
			}
		}
		else dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
