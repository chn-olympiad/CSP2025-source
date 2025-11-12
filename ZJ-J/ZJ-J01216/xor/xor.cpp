#include <bits/stdc++.h>
using namespace std;
long long l[500005],qzh[500005];
long long he(long long lef,long long rig){
	return qzh[rig] ^ qzh[lef-1];
}
struct node{
	long long start,finish;
};
node lst[500005];
bool cmp(node q,node h){
	return q.finish<h.finish;
}
//map<long long, long long > ma;
//map<long long,bool>vis;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,len = 0;
	cin >> n >> k;
	for(long long i = 1;i<=n;i++){
		cin >> l[i];
		if(i==1){
			qzh[i] = l[i];
		}else{
			qzh[i] = qzh[i-1] ^ l[i];
		}
	}
	
	for(long long i = 1;i<=n;i++){
		for(long long j = 1;j<=i;j++){
			
			if(he(j,i)==k){
				lst[++len] = {j,i};
			}
		}
	}
//	for(long long i = 1;i<=n;i++){	
//		ma[qzh[i]]=i;
//		vis[qzh[i]]=1;
//		ma[qzh[i] ^ k]+1>=0 && ma[qzh[i] ^ k]+1<i
//		if(vis[qzh[i] ^ k]==1){
//			lst[++len] = {ma[qzh[i] ^ k]+1,i};
//
//		}
//		if(l[i]==k)	{
//			lst[++len] = {i,i};
//
//		}
//	}
	sort(lst+1,lst+len+1,cmp);
	long long ans = 0,now = 0;
	for(long long i = 1;i<=len;i++){
		if(lst[i].start>now){
			ans++;
			now = lst[i].finish;
		}
	}
	cout << ans;
	return 0;
}
