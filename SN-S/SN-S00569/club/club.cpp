#include <bits/stdc++.h>
using namespace std;
int t,n,X,Y,Z,cnt,num,now=1,k[100005][3];
long long ans;
struct CLUB{
	int from;
	int where;
	int much;
}a[3000015];
bool p[100005];
int A[3],last[3];
bool cmp(CLUB A,CLUB B){
	return A.much>B.much;
}
int zhao(int ip,int o){
	int o1;
	int o2;
	if(o==1){
		o1=2;
		o2=3;
	}
	else if(o==2){
		o1=1;
		o2=3;
	}
	else{
		o1=1;
		o2=2;
	}
	if(k[ip][o]>=k[ip][o1]&&k[ip][o]>=k[ip][o2]){
		if(k[ip][o1]>=k[ip][o2]) return o1;
		else return o2;
	}
	else if(k[ip][o1]>=k[ip][o]&&k[ip][o]>=k[ip][o2]) return o2;
	else return o1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int u=1;u<=t;u++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>X>>Y>>Z;
			k[i][1]=X;
			k[i][2]=Y;
			k[i][3]=Z;
			cnt++;
			a[cnt].from=i;
			a[cnt].much=X;
			a[cnt].where=1;
			cnt++;
			a[cnt].from=i;
			a[cnt].much=Y;
			a[cnt].where=2;
			cnt++;
			a[cnt].from=i;
			a[cnt].much=Z;
			a[cnt].where=3;
		}
		sort(a+1,a+3*n+1,cmp);
		while(num<=n&&now<=3*n){
			if(p[a[now].from]==0&&A[a[now].where]<n/2){
				A[a[now].where]++;
				p[a[now].from]=1;
				ans+=a[now].much;
				last[a[now].where]=a[now].from;
				num++;
			}
			else if(p[a[now].from]==0&&A[a[now].where]==n/2){
				if(k[last[a[now].where]][zhao(last[a[now].where],a[now].where)]+a[now].much>k[last[a[now].where]][a[now].where]+k[a[now].from][zhao(a[now].from,a[now].where)]){
					ans-=k[last[a[now].where]][a[now].where];
					ans+=k[last[a[now].where]][zhao(last[a[now].where],a[now].where)]+a[now].much;
					A[zhao(last[a[now].where],a[now].where)]++;
					last[a[now].where]=a[now].from;
				}
			}
			now++;
		}
		cout<<ans;
		ans=0;
		cnt=0;
		num=0;
		now=1;
		A[1]=A[2]=A[3]=0;
		last[1]=last[2]=last[3]=0;
		for(int i=1;i<=n;i++) p[i]=0;
	}
	return 0;
}
