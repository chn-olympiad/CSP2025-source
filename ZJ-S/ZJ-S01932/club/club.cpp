#include<bits/stdc++.h>
using namespace std;
int a[100010][5],n;
int cnt[100010][5],tot[5];
int b[100010];  
int calc(int m){
	sort(b+1,b+m+1);
	int s=0;
	for(int i=1;i<=(m-n/2);i++){
		s+=b[i];
	}
	return s;
}
int solve(){
	if(tot[1]>n/2){
		memset(b,0,sizeof(b));
		for(int i=1;i<=tot[1];i++){
			int id=cnt[i][1];
			b[i]=(a[id][1]-max(a[id][2],a[id][3]));
		}
		return calc(tot[1]);
	}else if(tot[2]>n/2){
		memset(b,0,sizeof(b));
		for(int i=1;i<=tot[2];i++){
			int id=cnt[i][2];
			b[i]=(a[id][2]-max(a[id][1],a[id][3]));
		}
		return calc(tot[2]);
	}else{
		memset(b,0,sizeof(b));
		for(int i=1;i<=tot[3];i++){
			int id=cnt[i][3];
			b[i]=(a[id][3]-max(a[id][1],a[id][2]));
		}
		return calc(tot[3]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		memset(cnt,0,sizeof(cnt));
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				cnt[++tot[1]][1]=i;
			}else if(a[i][2]>a[i][3]){
				cnt[++tot[2]][2]=i;
			}else{
				cnt[++tot[3]][3]=i;
			}
		}
//		if(tot[1]<=(n/2)&&tot[2]<=(n/2)&&tot[3]<=(n/2)){
		int sum=0;
		for(int i=1;i<=tot[1];i++){
			sum+=a[cnt[i][1]][1];
		}
		for(int i=1;i<=tot[2];i++){
			sum+=a[cnt[i][2]][2];
		}
		for(int i=1;i<=tot[3];i++){
			sum+=a[cnt[i][3]][3];
		}
//		}
		int k=0;
		if(tot[1]>n/2||tot[2]>n/2||tot[3]>n/2) k=solve();
		cout<<sum-k<<endl;
	}
	return 0;
} 
