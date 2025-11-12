#include<bits/stdc++.h>
#define lnt long long
#define N 114514
#define pii pair<int,int> 
using namespace std;
inline int max(int i,int j,int k){
	return max(i,max(j,k));
}
inline int min(int i,int j,int k){
	return min(i,min(j,k));
}
inline int mid(int i,int j,int k){
	int b=max(i,j,k);
	int s=min(i,j,k);
	return i+j+k-s-b;
}
struct node{
	int _1,_2,_3;
}a[N];

bool cmp(node i,node j){
//	int ki=3*max(i._1,i._2,i._3)-i._1-i._2-i._3/*+mi-min(i._1,i._2,i._3)*/;
//	int kj=3*max(j._1,j._2,j._3)-j._1-j._2-j._3/*+mj-min(j._1,j._2,j._3)*/;
	int ki=max(i._1,i._2,i._3)-mid(i._1,i._2,i._3);
	int kj=max(j._1,j._2,j._3)-mid(j._1,j._2,j._3);
	return ki>kj;
}
bool cmppii(pii i,pii j){
	return i.first>j.first;
}
int b[4];
void solve(){
	int ans=0;
	int n;cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i]._1>>a[i]._2>>a[i]._3;
	}
	b[1]=b[2]=b[3]=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		pii t[4]={{114,514},{a[i]._1,1},{a[i]._2,2},{a[i]._3,3}};
//		cerr<<a[i]._1<<"	"<<a[i]._2<<"	"<<a[i]._3<<"\n";
		sort(t+1,t+4,cmppii);
		for(int j=1;j<=3;j++){
			if(b[t[j].second]==n/2){
				continue;
			}else{
				b[t[j].second]+=1;
				ans+=t[j].first;
				break;
			}
		}
	}
	cout<<ans<<"\n";
///	cerr<<"\n\n";
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
//		1
/*
18
4
13
*///\
		2
/*
147325
125440
152929
150176
158541
*///\
		3
/*
447450
417649
473417
443896
484387
*///\
		4
/*
2211746
2527345
2706385
2710832
2861471
*///\
		5
/*
1499392690
1500160377
1499846353
1499268379
1500579370
*/
/*
好耶 终于做出来了 看来上厕所大法是管用的耶

oiiaioiiai 
*/ 
