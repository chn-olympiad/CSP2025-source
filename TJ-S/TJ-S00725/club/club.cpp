#include<bits/stdc++.h>
using namespace std;

int a[100005][4];
bool ch[100005][4];
int tot[4];
bool is[100005];
struct change{
	int num;
	int from;
	int to;
	int val;
};
change m[500000];
bool cmp(change c1,change c2){
	return c1.val>c2.val;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=3;i++){
		tot[i]=0;
	}
	for(int i=1;i<=n;i++){
		is[i]=0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int mx=0,cb=0;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>mx){
				mx=a[i][j];
				cb=j;
			}
		}
		ans+=a[i][cb];
		ch[i][1]=0;
		ch[i][2]=0;
		ch[i][3]=0;
		ch[i][cb]=1;
		tot[cb]++;
	}
	int out=-1,cnt=0;
	for(int i=1;i<=3;i++){
		if(tot[i]>n/2){
			out=i;
			for(int j=1;j<=n;j++){
				if(ch[j][i]==1){
					
					for(int k=1;k<=3;k++){
						if(k!=i){
							cnt++;
							m[cnt].num=j;
							m[cnt].from=i;
							m[cnt].to=k;
							m[cnt].val=a[j][k]-a[j][i];
						}
					}
				}
			}
			break;
		}
	}
	if(out==-1){
		cout<<ans<<"\n";
		return ;
	}
	sort(m+1,m+cnt+1,cmp);
	int i=0;
	while(tot[out]>n/2){
		i++;
		if(tot[m[i].to]==n/2)continue;
		tot[m[i].from]--;
		tot[m[i].to++];
		ch[m[i].num][m[i].from]=0;
		ch[m[i].num][m[i].to]=1;
		ans+=m[i].val;
	}
	cout<<ans<<"\n";
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}

