#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,d[N][3],a[N],b[N],c[N],ai,bi,ci,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		ai=0,bi=0,ci=0,ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i][0]>>d[i][1]>>d[i][2];
			if(d[i][0]>=d[i][1]&&d[i][0]>=d[i][2]){
				ans+=d[i][0];
				if(d[i][1]>d[i][2]){
					a[++ai]=d[i][0]-d[i][1];
				}else{
					a[++ai]=d[i][0]-d[i][2];
				}
			}else if(d[i][1]>=d[i][0]&&d[i][1]>=d[i][2]){
				ans+=d[i][1];
				if(d[i][0]>d[i][2]){
					b[++bi]=d[i][1]-d[i][0];
				}else{
					b[++bi]=d[i][1]-d[i][2];
				}
			}else{
				ans+=d[i][2];
				if(d[i][0]>d[i][1]){
					c[++ci]=d[i][2]-d[i][0];
				}else{
					c[++ci]=d[i][2]-d[i][1];
				}
			}
		}
		int num;
		if(ai>n/2){
			sort(a+1,a+1+ai);
			num=ai-n/2;
			for(int i=1;i<=num;i++){
				ans-=a[i];
			}
		}else if(bi>n/2){
			sort(b+1,b+1+bi);
			num=bi-n/2;
			for(int i=1;i<=num;i++){
			ans-=b[i];
			}
		}else if(ci>n/2){
			sort(c+1,c+1+ci);
			num=ci-n/2;
			for(int i=1;i<=num;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
