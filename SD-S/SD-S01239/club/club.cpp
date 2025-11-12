#include<bits/stdc++.h>
#define cs1 A[i][1]
#define cs2 A[i][2]
#define cs3 A[i][3]
using namespace std;

const int N=1e5+5;

struct member{
	int id,score;
}a[N][5];

struct ch{
	int memb,chan,chc;
}cha1[N];

int n,app[5],decit[N],pos1,sum,A[N][5];

bool cmp1(member b,member c){return b.score>c.score;}
bool cmp2(ch d,ch e){return d.chan<e.chan;}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while (t--){
  		pos1=0,sum=0;
		memset(app,0,sizeof app);
		cin>>n;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++)
				cin>>a[i][j].score,a[i][j].id=j,A[i][j]=a[i][j].score;
			sort(a[i]+1,a[i]+4,cmp1);
			app[a[i][1].id]++,decit[i]=a[i][1].id;
		}//Swap
		if (app[1]>n/2){
			for (int i=1;i<=n;i++)
				if (decit[i]==1){
					cha1[++pos1].chan=abs(cs1-max(cs2,cs3));
					if (cs2>cs3)
						cha1[pos1].chc=2;
					else
						cha1[pos1].chc=3;
					cha1[pos1].memb=i;
				}
			sort(cha1+1,cha1+pos1+1,cmp2);
			for (int i=1;app[1]>n/2;i++,app[1]--){
				app[cha1[i].chc]++;
				decit[cha1[i].memb]=cha1[i].chc;
			}
		}else if (app[2]>n/2){
			for (int i=1;i<=n;i++)
				if (decit[i]==2){
					cha1[++pos1].chan=abs(cs2-max(cs1,cs3));
					if (cs1>cs3)
						cha1[pos1].chc=1;
					else
						cha1[pos1].chc=3;
					cha1[pos1].memb=i;
				}
			sort(cha1+1,cha1+pos1+1,cmp2);
			for (int i=1;app[2]>n/2;i++,app[2]--){
				app[cha1[i].chc]++;
				decit[cha1[i].memb]=cha1[i].chc;
			}
		}else{
			for (int i=1;i<=n;i++)
				if (decit[i]==3){
					cha1[++pos1].chan=abs(cs3-max(cs1,cs2));
					if (cs1>cs2)
						cha1[pos1].chc=1;
					else
						cha1[pos1].chc=2;
					cha1[pos1].memb=i;
				}
			sort(cha1+1,cha1+pos1+1,cmp2);
			for (int i=1;app[3]>n/2;i++,app[3]--){
				app[cha1[i].chc]++;
				decit[cha1[i].memb]=cha1[i].chc;
			}
		}for (int i=1;i<=n;i++)
			sum+=A[i][decit[i]];
		cout<<sum<<'\n';
	}return 0;
}
