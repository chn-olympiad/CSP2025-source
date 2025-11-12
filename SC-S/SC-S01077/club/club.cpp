#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,a[100010][4],ans,maxx,x,y,z,idx;
bool flaga=true,flagb=true,color[100010];
struct node{
	int id,t,p,diff;
}w[400010];
/*void subtaska(){
	sort(b+1,b+n+1);
	ans=0;
	for(int i=n;i>=n/2+1;i--){
		ans+=b[i];
	}
	cout<<ans<<endl;
	return;
}*/
bool operator < (node xx,node yy){
	return xx.diff<yy.diff;
}
void final(){
	memset(color,0,sizeof(color));
	x=y=z=idx=ans=0;
	for(int i=1;i<=n;i++){
		maxx=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=maxx;
		if(a[i][1]==maxx){
			x++;
			w[++idx]={i,1,2,a[i][1]-a[i][2]};
			w[++idx]={i,1,3,a[i][1]-a[i][3]};
		}else{
			if(a[i][2]==maxx){
				y++;
				w[++idx]={i,2,1,a[i][2]-a[i][1]};
				w[++idx]={i,2,3,a[i][2]-a[i][3]};
			}else{
				z++;
				w[++idx]={i,3,1,a[i][3]-a[i][1]};
				w[++idx]={i,3,2,a[i][3]-a[i][2]};
			}
		}
	}
	if(x<=n/2&&y<=n/2&&z<=n/2){
		cout<<ans<<endl;
		return;
	}
	int k,cnt;
	if(x>n/2)k=1,cnt=x;
	if(y>n/2)k=2,cnt=y;
	if(z>n/2)k=3,cnt=z; 
	sort(w+1,w+1+idx);
	for(int i=1;i<=idx;i++){
		if(cnt<=n/2)break;
		if(w[i].t==k&&!color[w[i].id]){
			ans-=w[i].diff;
			color[w[i].id]=true;
			cnt--;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			//b[i]=a[i][1];
			//if(a[i][2]!=0||a[i][3]!=0)flaga=false;
			//if(a[i][3]!=0)flagb=false;
		}
		/*if(n<=200){
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=min(i-j,n/2);k++){
						if(j+k<i&&i-(j+k)<=n/2)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
						if(j!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
						if(k!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
					}
				}
			}
			ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++)ans=max(ans,f[n][i][j]);
			}
			cout<<ans<<endl;
			continue;
		}
		if(flaga){
			subtaska();
			continue;
		}*/
		final();
	}
	return 0;
} 