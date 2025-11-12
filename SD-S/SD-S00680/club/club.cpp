#include<bits/stdc++.h>
#define ll long long
#define lll __int128
#define mp(a,b) make_pair(a,b);
#define fi first
#define se second
using namespace std; 
const int N=3e5+1145;

int t,n;
int a[N][5],tmp[N];

int gtans(int x){
	int tans=0;
	for(int i=1;i<=n;i++){
		tans+=a[i][x];
		tmp[i]=0;
		if(x!=0) tmp[i]=max(tmp[i],a[i][0]);
		if(x!=1) tmp[i]=max(tmp[i],a[i][1]);
		if(x!=2) tmp[i]=max(tmp[i],a[i][2]);
		tmp[i]-=a[i][x];
    }
    sort(tmp+1,tmp+n+1);
    for(int i=n;i>n/2;i--) tans+=tmp[i];
    for(int i=n/2;tmp[i]>0&&i>=1;i--) tans+=tmp[i];
    return tans;
    
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	int ans=min(gtans(0), min( gtans(1),gtans(2) ) );
	printf("%d\n",ans);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        sol();
	}
	return 0;
}

