#include<bits/stdc++.h>
using namespace std;
#define max3(a,b,c) max(a,max(b,c))
const int N=1e5+5;
int n,a[N][4],b[N],t[N];
int mid(int x,int y,int z){
	return x+y+z-max3(x,y,z)-min(x,min(y,z));
}
void work(){
	memset(t,0,sizeof(t));
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)
			scanf("%d",&a[i][j]);
		int tmp=max3(a[i][1],a[i][2],a[i][3]);
		cnt+=tmp;
		if(a[i][1]==tmp) t[1]++,b[i]=1;
		else if(a[i][2]==tmp) t[2]++,b[i]=2;
		else t[3]++,b[i]=3;
	}
	if(max3(t[1],t[2],t[3])<=n/2){
		printf("%d\n",cnt);
		return;
	}
	int p=0;
	for(int i=1;i<=3;i++) if(t[i]>t[p]) p=i;
	vector<int> q; q.clear();
	for(int i=1;i<=n;i++)
		if(b[i]==p) q.push_back(max3(a[i][1],a[i][2],a[i][3])-mid(a[i][1],a[i][2],a[i][3]));
	sort(q.begin(),q.end());
	for(int i=0;i<t[p]-n/2;i++)
		cnt-=q[i];
	printf("%d\n",cnt);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--) work();
	return 0;
}