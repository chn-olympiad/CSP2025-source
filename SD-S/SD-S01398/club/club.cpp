#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,t,sum;
int c[4];
struct Node{
	pair<int,int> m[4];
	int sa,sb;
	Node(){
		memset(m,0,sizeof(m));
	}
}a[N];
bool cmp(pair<int,int> q,pair<int,int> e){
	return q.first>e.first;
}
bool cmpp(Node xx,Node yy){
	if(xx.sa!=yy.sa)
	return xx.sa>yy.sa;
	else
	return xx.sb>yy.sb;
} 
int read(){
	int f=1,x=0;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')
		f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for (int k=1;k<=t;k++){
		n=read();
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++)
			a[i].m[j].first=read(),a[i].m[j].second=j;
			sort(a[i].m+1,a[i].m+4,cmp);
			a[i].sa=a[i].m[1].first-a[i].m[2].first;
			a[i].sb=a[i].m[2].first-a[i].m[3].first;
		}
		sort(a+1,a+n+1,cmpp);
		for (int i=1;i<=n;i++){
			if(c[a[i].m[1].second]*2<n)
			sum+=a[i].m[1].first,c[a[i].m[1].second]++;
			else if(c[a[i].m[2].second]*2<n)
			sum+=a[i].m[2].first,c[a[i].m[2].second]++;
			else if(c[a[i].m[3].second]*2<n)
			sum+=a[i].m[3].first,c[a[i].m[3].second]++;
		}
		printf("%d\n",sum);
		sum=0;
		memset(c,0,sizeof(c));
	}
	return 0;
}
