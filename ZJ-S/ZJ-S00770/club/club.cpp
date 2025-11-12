//long long
#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
struct cyc{
	long long l,id;
	bool operator <(const cyc c)const{
		return l>c.l;
	}
};
long long a[N][3],ch[N],want2[N],ans,siz[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		siz[0]=siz[1]=siz[2]=ans=0;
		priority_queue<cyc> f[3];
		long long manyuan=-1; 
		for(long long i=1;i<=n;i++){
			long long maxs=-1,maxid,mexs=-1,mexid;
			for(long long j=0;j<=2;j++){
				cin>>a[i][j];
				if(a[i][j]>maxs){
					mexs=maxs,mexid=maxid;
					maxs=a[i][j],maxid=j;
				}
				else if(a[i][j]>mexs){
					mexs=a[i][j],mexid=j;
				}
			}
			want2[i]=mexid;
			if(siz[maxid]<(n>>1)){
				siz[maxid]++;
				ch[i]=maxid;
				if(manyuan==-1||manyuan==maxid)f[maxid].push({maxs-mexs,i});
				if(siz[maxid]==(n>>1))manyuan=maxid;
			}
			else{
				manyuan=maxid;
				long long isad=maxs-mexs,u=f[maxid].top().id,usad=f[maxid].top().l;
				if(isad<=usad){
					ch[i]=mexid;
				}
				else{
					f[maxid].pop();
					f[maxid].push({maxs-mexs,i});
					ch[u]=want2[u];
					ch[i]=maxid; 
				}
			}
		}
		for(long long i=1;i<=n;i++){
			ans+=a[i][ch[i]];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
一共3个部门，每个部门不超过n/2人
n=n/2+n/2 (n为偶数) 
也就是说，当有人正在选择时，最多只会有1个部门满员
那么只要先考虑TA最想去的部门，如果未满就万事大吉 
如果满员再考虑把TA或该部门的修改损失最少的人转去他们第2想去的部门(一定能去) 
另外，一旦发生满员，就只需记录剩余每个人的选择并维护满员的部门的优先队列 
*/
