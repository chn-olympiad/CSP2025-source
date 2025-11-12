#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int _MAXn=1e5+100;

int n;
int num[3][_MAXn];
int argm[_MAXn];
int wei[_MAXn];
int cnt[3];
int id=0;
int len=0;
int cwei[_MAXn];
int ans=0;

int tmp[3];

void Solve(){
	cnt[0]=cnt[1]=cnt[2]=0;
	ans=0;
	len=0;
	id=-1;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&num[0][i],&num[1][i],&num[2][i]);
		tmp[0]=num[0][i];
		tmp[1]=num[1][i];
		tmp[2]=num[2][i];
		sort(tmp,tmp+3);
		if(num[2][i]==tmp[2])argm[i]=2;
		if(num[1][i]==tmp[2])argm[i]=1;
		if(num[0][i]==tmp[2])argm[i]=0;
		cnt[argm[i]]++;
		wei[i]=tmp[2]-tmp[1];
		ans+=tmp[2];
	} 
	if(cnt[0]>n/2)id=0;
	if(cnt[1]>n/2)id=1;
	if(cnt[2]>n/2)id=2;
	if(id==-1){
		printf("%d\n",ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(argm[i]==id)cwei[++len]=wei[i];
	}
	sort(cwei+1,cwei+len+1);
	for(int i=1;i<=cnt[id]-n/2;i++){
		ans-=cwei[i];
	} 
	printf("%d\n",ans);
}

int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(;T;T--){
		Solve();
	}
	return 0;
}
