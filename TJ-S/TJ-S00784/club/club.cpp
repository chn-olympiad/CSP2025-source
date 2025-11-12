#include<bits/stdc++.h>
using namespace std;
int T,n;
const int mxn=1e5+5;
struct nd{
	int x,y;
};

bool cmp(nd i,nd j){
	return i.x>j.x;
}
int v[100005],ans,tst[200005],cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cnt=0;
		cin>>n;
		vector<nd> a[3];
		bool ts=true;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				int x;
				cin>>x;
				a[j].push_back({x,i});
				tst[++cnt]=x;
				if (j!=0&&x!=0) ts=false;
			}
		}
		if (ts){
			sort(tst+1,tst+cnt+1);
			for(int i=cnt;i>=1;i--){
				if (cnt-i+1>n/2) break;
				ans+=tst[i];
			}
			cout<<ans<<endl;
		}else{
			for(int i=0;i<3;i++){
				sort(a[i].begin(),a[i].end(),cmp);
			}
			int nm[4]={},z[mxn];
			memset(v,-1,sizeof(v));
			for(int q=0;q<n;q++){
				for(int i=0;i<3;i++){
					nd t=a[i][q];
					if (v[t.y]!=-1) continue;
					if (nm[i]<n/2){
						v[t.y]=i;
						nm[i]++;
						z[t.y]=q;
						ans+=t.x;
					}
					else{
						for(int j=1;j<=n;j++){
							if (v[j]==i){
								bool f=false;
								int k=0,l=0;
								for(k=0;k<n;k++){
									for(l=0;l<3;l++){
										if (a[l][k].y==j&&nm[k]<n/2){
											f=true;
											break;
										}
									}
									if (f) break;
								}
								if (!f) continue;
								ans-=a[v[j]][j].x;
								nd p=a[l][k];
								ans+=p.x;
								z[j]=k;
								v[j]=l;
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
