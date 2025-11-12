#include<bits/stdc++.h>
using namespace std;
int n,ans,_,an[100005][4],cnt[4],op[100005],c[4][100005];
inline bool cmp(int u,int v){return u<v;}
void cl(int p,int now){
	if (p==0){
		cout<<now<<endl;
		return;
	}
	for (int i=1;i<=cnt[p];i++){
		op[i]=114514;
		for (int j=1;j<=3;j++){
			if (j==p) continue;
			op[i]=min(op[i],c[p][an[i][p]]-c[j][an[i][p]]);
		}
	}
	sort(op+1,op+cnt[p]+1,cmp);
	int no=1;
	while (cnt[p]>(int)(n/2)) now-=op[no++],cnt[p]--;
	cout<<now<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while (_--){
		cin>>n;
		memset(op,0,sizeof(op));
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		for (int i=1;i<=n;i++){
			int k=0;
			cin>>c[1][i]>>c[2][i]>>c[3][i];
			if (c[1][i]>c[2][i]){
				if (c[1][i]>=c[3][i]) k=1;
				else k=3;
			}
			else{
				if (c[2][i]>=c[3][i]) k=2;
				else k=3;
			}
			an[++cnt[k]][k]=i;
			ans+=c[k][i];
		}
		int k=0;
		if (cnt[1]>(int)(n/2)) k=1;
		if (cnt[2]>(int)(n/2)) k=2;
		if (cnt[3]>(int)(n/2)) k=3;
		cl(k,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
