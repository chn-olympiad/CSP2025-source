#include <bits/stdc++.h>

using namespace std;

struct node{
	int l,r;
}a[500010];

inline bool cmp(node A,node B){
	return A.r<B.r;
}

int n,id;
long long k;
long long b[500010];
long long s[500010]; 
map<long long,vector<int> >c;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]^b[i];
	for(int i=n;i>=1;i--)
		c[s[i]].push_back(i);
	for(int i=1;i<=n;i++){
		long long cnt=k^s[i-1];
		if(c[cnt].size()>0){
			int l=0,r=c[cnt].size();
			while(l+1<r){
				int m=(l+r)/2;
				if(c[cnt][m]>=i)
					l=m;
				else
					r=m;
			}
			if(c[cnt][l]>=i)
				a[++id].l=i,a[id].r=c[cnt][l];
		}
	}
	sort(a+1,a+id+1,cmp);
	int sum=0;
	int ma=0;
	for(int i=1;i<=id;i++){
		if(i==1)
			sum++,ma=max(ma,a[i].r);
		else{
			if(a[i].l>ma)
				sum++,ma=max(ma,a[i].r);
		}
	}
	printf("%d",sum);
	return 0;
} 
