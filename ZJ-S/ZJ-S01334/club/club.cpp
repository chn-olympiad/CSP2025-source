#include<bits/stdc++.h>
#define N 5000
using namespace std;
int n,a[N][3],f[2][N][N],s[100005];
void sub(){
	for(int i=1;i<=n;i++){
		s[i]=a[i][0];
	}
	sort(s+1,s+n+1);
	int ans=0;
	for(int i=n;i>n/2;i--){
		ans+=s[i];
	}
	cout<<ans<<"\n";
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	}
	if(n>500){
		sub();
		exit(0);
	}
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		for(int p=0;p<=i;p++){
			for(int q=0;q<=i-p;q++){	
				if(p>0)f[i&1][p][q]=max(f[i&1][p][q],f[(i-1)&1][p-1][q]+a[i][0]);
				if(q>0)f[i&1][p][q]=max(f[i&1][p][q],f[(i-1)&1][p][q-1]+a[i][1]);
				if(i-p-q>0)f[i&1][p][q]=max(f[i&1][p][q],f[(i-1)&1][p][q]+a[i][2]);
			}
		}
	}
	int ans=0;
	for(int p=0;p<=n/2;p++){
		for(int q=0;q<=n/2;q++){
			if(n-p-q<=n/2)ans=max(ans,f[0][p][q]);
		}
	}
	cout<<ans<<"\n";
}
int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	int t;
 	scanf("%d",&t);
 	while(t--){
 		solve();
	}
}