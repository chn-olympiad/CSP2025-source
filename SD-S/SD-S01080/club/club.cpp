#include<iostream>//CSP-S T1
#include<cstdio>//100
#include<algorithm>
using namespace std;
const int N=1e5+5;
int T,n,k,a[N][5];
int mx,maxn;
int op,lk[N],num[5];
int srt[N],cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		maxn=n/2;
		mx=0;
		num[1]=num[2]=num[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) lk[i]=1;
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) lk[i]=2;
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) lk[i]=3;
			mx+=a[i][lk[i]];
			num[lk[i]]++;
		}
		op=0;
		if(num[1]>maxn) op=1,k=num[1]-maxn;
		if(num[2]>maxn) op=2,k=num[2]-maxn;
		if(num[3]>maxn) op=3,k=num[3]-maxn;
		if(op==0){
			cout<<mx<<endl;
			continue;
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(lk[i]!=op) continue;
			if(op==1) srt[++cnt]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			if(op==2) srt[++cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			if(op==3) srt[++cnt]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
		} 
		sort(srt+1,srt+1+cnt);
		for(int i=1;i<=min(cnt,k);i++){
			mx-=srt[i];
		}
		cout<<mx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
