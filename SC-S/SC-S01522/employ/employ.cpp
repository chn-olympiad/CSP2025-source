#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int f[MAXN],qw[5];
struct s{
	int a[5],ma;
	
}clubs[MAXN];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t>0){
		int n,ans=0;
		memset(clubs,0,sizeof(clubs));
		memset(f,-1,sizeof(f));
		memset(qw,0,sizeof(qw));
		scanf("%d",&n);
		int e=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&clubs[i].a[1],&clubs[i].a[2],&clubs[i].a[3]);
			clubs[i].ma=max(clubs[i].a[1],max(clubs[i].a[2],clubs[i].a[3]));
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j+i<=n;j++){
				if(clubs[i].ma<clubs[i+j].ma){
					swap(clubs[i].ma,clubs[i+j].ma);
					swap(clubs[i].a,clubs[i+j].a);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(qw[1]<e&&qw[2]<e&&qw[3]<e)f[i]=max(clubs[i].a[1],max(clubs[i].a[2],clubs[i].a[3]));
			if(qw[1]>=e&&qw[2]<e&&qw[3]<e)f[i]=max(-1,max(clubs[i].a[2],clubs[i].a[3]));
			if(qw[1]>=e&&qw[2]>=e&&qw[3]<e)f[i]=max(-1,max(-1,clubs[i].a[3]));
			if(qw[1]>=e&&qw[2]<e&&qw[3]>=e)f[i]=max(-1,max(clubs[i].a[2],-1));
			if(qw[1]<e&&qw[2]>=e&&qw[3]<e)f[i]=max(clubs[i].a[1],max(-1,clubs[i].a[3]));
			if(qw[1]<e&&qw[2]>=e&&qw[3]>=e)f[i]=max(clubs[i].a[1],-1);
			if(qw[1]<e&&qw[2]<e&&qw[3]>=e)f[i]=max(clubs[i].a[1],max(clubs[i].a[2],-1));
			if(f[i]==clubs[i].a[1])qw[1]++;
			else if(f[i]==clubs[i].a[2])qw[2]++;
			else if(f[i]==clubs[i].a[3])qw[3]++;
		}
		for(int i=1;i<=n;i++){
			ans+=f[i];
		}
		printf("%d\n",ans);
		t--;
	}
	return 0;
}