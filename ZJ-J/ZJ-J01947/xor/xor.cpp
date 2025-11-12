#include<bits/stdc++.h>
using namespace std;
int n,k,s,a[500005],t;
struct bu{
	int s,e;
}m[500005];
bool cmp(bu i,bu j){
	if(i.e==j.e)return i.s>j.s;
	return i.e<j.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			m[++t].s=i,m[t].e=i;
			continue;
		}
		int tp=a[i];
		for(int j=i-1;j>0;j--){
			tp=tp xor a[j];
			if(tp==k){
				m[++t].s=j,m[t].e=i;
				break;
			}
		}
	}
	sort(m+1,m+1+t,cmp);
	int p=0;
	for(int i=1;i<=t;i++){
		if(m[i].s>p)s++,p=m[i].e;
	}
	printf("%d",s);
	return 0;
}
