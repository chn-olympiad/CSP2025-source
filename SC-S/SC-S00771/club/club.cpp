#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,maxn,ans[N],a,b,c,tt[N][4],t,ta[N],tb[N],tc[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	for(int l=1;l<=t;l++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&tt[i][1],&tt[i][2],&tt[i][3]);
			maxn=max(tt[i][1],max(tt[i][2],tt[i][3]));
			ans[l]+=maxn;
			if(maxn==tt[i][1]) {a++;ta[i]=tt[i][1]-tt[i][2];ta[i+n]=tt[i][1]-tt[i][3];}
			if(maxn==tt[i][2]&&(b<=a||maxn!=tt[i][1])){b++;tb[i]=tt[i][2]-tt[i][1];tb[i+n]=tt[i][2]-tt[i][3];}
			if(maxn==tt[i][3]&&(c<a||maxn!=tt[i][1])){c++;tc[i]=tt[i][3]-tt[i][1];tc[i+n]=tt[i][3]-tt[i][2];}
		}
		if(a<=n/2&&b<=n/2&&c<=n/2) continue;
		if(a>n/2){
			int temp=a-n/2;
			sort(ta+1,ta+n+1);
			sort(ta+n+2,ta+2*n+2);
			for(int i=1;i<=temp;i++) ans[l]-=min(ta[i],ta[i+n]);
		}
		if(b>n/2){
			int temp=b-n/2;
			sort(tb+1,tb+n+1);
			sort(tb+n+2,tb+2*n+2);
			for(int i=1;i<=temp;i++) ans[l]-=min(tb[i],tb[i+n]);
		}
		if(c>n/2){
			int temp=c-n/2;
			sort(tc+1,tc+n+1);
			sort(tc+n+2,tc+2*n+2);
			for(int i=1;i<=temp;i++) ans[l]-=min(tc[i],tc[i+n]);
		}
		a=b=c=0;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}