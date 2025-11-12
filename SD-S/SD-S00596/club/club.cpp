#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N],c[N],chg[N];
int chs[N];
priority_queue<int> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(chg,0,sizeof(chg));
		memset(chs,0,sizeof(chs));
		while(!q.empty()){
			q.pop();
		}
		int n;
		int ans=0;
		int cnta=0,cntb=0,cntc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			int mxx=max(a[i],b[i]);
			mxx=max(mxx,c[i]);
			ans+=mxx;
			if(a[i]==mxx){
				chs[i]=1;
				cnta++;
			}
			else if(b[i]==mxx){
				chs[i]=2;
				cntb++;
			}
			else {
				chs[i]=3;
				cntc++;
			}
		}
		if((cnta<=n/2)&&(cntb<=n/2)&&(cntc<=n/2)){
			
		}
		else{
			if(cnta>n/2){
				for(int i=1;i<=n;i++){
					if(chs[i]==1){
						int hange=0x3f3f3f3f;
						hange=min(hange,a[i]-b[i]);
						hange=min(hange,a[i]-c[i]);
						q.push(-hange);
					}
				}
				for(int i=1;i<=cnta-n/2;i++){
					if(q.empty()) break;
					ans+=q.top();
					q.pop();
				}
			}
			else if(cntb>n/2){
				for(int i=1;i<=n;i++){
					if(chs[i]==2){
						int hange=0x3f3f3f3f;
						hange=min(hange,b[i]-a[i]);
						hange=min(hange,b[i]-c[i]);
						q.push(-hange);
					}
				}
				for(int i=1;i<=cntb-n/2;i++){
					if(q.empty()) break;
					ans+=q.top();
					q.pop();
				}
			} 
			else{
				for(int i=1;i<=n;i++){
					if(chs[i]==3){
						int hange=0x3f3f3f3f;
						hange=min(hange,c[i]-b[i]);
						hange=min(hange,c[i]-a[i]);
						q.push(-hange);
					}
				}
				for(int i=1;i<=cntc-n/2;i++){
					if(q.empty()) break;
					ans+=q.top();
					q.pop();
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
