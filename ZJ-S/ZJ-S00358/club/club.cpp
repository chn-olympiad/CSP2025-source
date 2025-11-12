#include<bits/stdc++.h>
using namespace std;
int a[200005][5];
int tim[5];
int sum[200005];
int da[200005];
int xiao[200005];
struct node{
	int cha;
	int ind;
}mincha[200005];

int b[200005][5];

bool cmp(node x,node y){
	if(x.cha==y.cha )return x.ind<y.ind;
	return x.cha<y.cha;
}

int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(tim,0,sizeof(tim));
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		memset(da,0,sizeof(da));
		memset(xiao,0,sizeof(xiao));
		memset(mincha,0,sizeof(mincha));
		int ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sum[i]=a[i][1]+a[i][2]+a[i][3];
			da[i]=max(a[i][1],max(a[i][2],a[i][3]));
			xiao[i]=min(a[i][1],min(a[i][2],a[i][3]));
			mincha[i].cha=da[i]-(sum[i]-da[i]-xiao[i]);
			mincha[i].ind=i;
			ans+=da[i];
		}
		sort(mincha+1,mincha+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]==da[i]){
					tim[j]++;
					b[i][j]=1;
				}
			}
		}
		for(int i=1;i<=3;i++){
			if(tim[i]>n/2){
			    int k=0;
				int kk=1;
				for(int j=1;j<=n;j++){
					if(k==tim[i]-n/2){
						break;
					}
					if(b[mincha[kk].ind][i]==1){
						ans-=mincha[kk].cha;
						k++;
						kk++;
					}else{
						kk++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
} 
