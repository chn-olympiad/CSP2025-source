#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
int t,n,ans,a[100010][5],b[100010],c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=rd();
	while(t--){
		ans=0;
		n=rd();
		int q=0,w=0,e=0;
		for(int i=1;i<=n;i++){
			int x=rd(),y=rd(),z=rd();
			if(x>=y&&x>=z){
				q++;
				b[i]=0;
				ans+=x;
			}
			else if(y>=x&&y>=z){
				w++;
				b[i]=1;
				ans+=y;
			}
			else{
				e++;
				b[i]=2;
				ans+=z;
			}
			a[i][0]=x;
			a[i][1]=y;
			a[i][2]=z;
		}
		if(w<=(n>>1)&&q<=(n>>1)&&e<=(n>>1)){
			cout<<ans<<'\n';
		}
		else{
			if(q>=w&&q>=e){
				
			int u=0;
			for(int i=1;i<=n;i++){
				if(b[i]==0){
					u++;
					c[u]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				}
			}
			sort(c+1,c+1+u);
			for(int i=1;i<=u-(n>>1);i++){
				ans-=c[i];
			}
			cout<<ans<<'\n';
			
			}
			else if(w>=q&&w>=e){
				
			int u=0;
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					u++;
					c[u]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				}
			}
			sort(c+1,c+1+u);
			for(int i=1;i<=u-(n>>1);i++){
				ans-=c[i];
			}
			cout<<ans<<'\n';
				
			}
			else{
				
			int u=0;
			for(int i=1;i<=n;i++){
				if(b[i]==2){
					u++;
					c[u]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
				}
			}
			sort(c+1,c+1+u);
			for(int i=1;i<=u-(n>>1);i++){
				ans-=c[i];
			}
			cout<<ans<<'\n';
				
			}
		}
	}
	return 0;
}