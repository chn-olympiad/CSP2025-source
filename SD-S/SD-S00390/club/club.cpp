#include<bits/stdc++.h>
using namespace std;
long long vis[100001],r1[1000001],r2[1000001],r3[1000001],t,n,m,ans,cnt,sizz[4],temp[5][5],maxans;
int dfsa[1000001];
map<long long,long long>mp,mp1;
/*struct myst2{
	int indexx,value;
	bool operator < (const myst &k)const{
	     return k.value>value;
	}
};*/
struct rt {
	int inn,v,g;
} kmax[100001],kmin[100001];
struct myst1 {
	int indexx,value,club;
} a[4][100001];
//priority_queue<myst>qu1;
bool cmp(myst1 a,myst1 b) {
	if(a.value ==b.value) {
		return a.indexx<b.indexx ;
	}
	return a.value>b.value ;
}
bool cmp1(rt a,rt b) {
	return a.v>b.v ;
}
void dfs(int step) {
	if(step>n) {
		long long ans=0;
		for(int i=1; i<=n; i++) {
			//	cout<<dfsa[i]<<" ";
			ans+=a[dfsa[i]][i].value ;
		}
		//	cout<<endl;
		maxans=max(ans,maxans);
		return ;
	}
	for(int i=1; i<=3; i++) {
		if(vis[i]<n/2) {
			dfsa[step]=i;
			vis[i]++;
			dfs(step+1);
			vis[i]--;
		}
	}
}


int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//myst p=qu1.top();
	cin>>t;
	while(t--) {
		cin>>n;
		maxans=0;
		if(n==2) {
			long long maxx=0;
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=3; j++) {
					cin>>temp[i][j];
				}
			}
			for(int i=1; i<=3; i++) {
				for(int j=1; j<=3; j++) {
					if(i!=j) {
						maxx=max(temp[1][i]+temp[2][j],maxx);
					}
				}
			}
			cout<<maxx<<endl;
			continue;
		}
		int k=n/2,sum12=0,sum3=0,sum23=0,p;
		ans=0;
		cnt=0;
		mp=mp1;
		memset(sizz,0,sizeof(sizz));
		for(int i=1; i<=n; i++) {
			cin>>a[1][i].value>>a[2][i].value>>a[3][i].value;
			a[1][i].indexx=i;
			a[2][i].indexx=i;
			a[3][i].indexx=i;
			if(a[2][i].value==0)sum23++;
			if(a[3][i].value==0)sum23++,sum3++;
		}

    /*
		if(sum3==n) {
			for(int i=1; i<=n; i++) {
				if(a[1][i].value>a[2][i].value)	{
					kmax[i].v=a[1][i].value;
					kmin[i].v=a[2][i].value;
					kmax[i].inn=i;
					kmin[i].inn=i;

				} else {
					kmax[i].v=a[2][i].value;
					kmin[i].v=a[1][i].value;
					kmax[i].inn=i;
					kmin[i].inn=i;
				}
			}
			sort(kmax+1,kmax+1+n,cmp1);
			sort(kmin+1,kmin+1+n,cmp1);
			int tempans=0,viss[1000001],tempcnt=0;
			memset(viss,0,sizeof(viss));
			for(int i=1; i<=n/2; i++) {
				tempans+=kmax[i].v;
				viss[kmax[i].inn]=1;
			}
			for(int i=1; i<=n; i++) {
				if(viss[kmin[i].inn]==0) {
					tempans+=kmax[i].v;
					viss[kmin[i].inn]=1;
					tempcnt++;
				}
				if(tempcnt==n/2)break;
			}
			cout<<tempans<<endl;
			continue;
		}*/
		if(sum23==2*n) {
			p=1;
			sort(a[p]+1,a[p]+1+n,cmp);
			for(int i=1; i<=k; i++) {
				ans+=a[p][i].value;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<30) {
			dfs(1);
			//	cout<<"11111aaa";
			cout<<maxans<<endl;
			continue;
		} else {
			sort(a[1]+1,a[1]+1+n,cmp);
			sort(a[2]+1,a[2]+1+n,cmp);
			sort(a[3]+1,a[3]+1+n,cmp);
			/*
					for(int i=1; i<=n; i++) {
						cout<<a[1][i].value<<" ";
					}
					cout<<endl;
					for(int i=1; i<=n; i++) {
						cout<<a[2][i].value<<" ";
					}
					cout<<endl;
					for(int i=1; i<=n; i++) {
						cout<<a[3][i].value<<" ";
					}
			*/
			//	dfs(1);
			for(int i=1; i<=n; i++) {
				for(int clubb=1; clubb<=3; clubb++) {
					if(mp[a[clubb][i].indexx]==0&&sizz[clubb]<k) {
						mp[a[clubb][i].indexx]=1;
						ans+=a[clubb][i].value;
						cnt++;
						sizz[clubb]++;
					}
					if(cnt==n) {
						break;
					}
				}
			}
			cout<<ans<<endl;
		}

	}
	return 0;
}
/*
 3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
11
1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 1
  2
 10 9 8
 4 0 0

 1
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
*/


