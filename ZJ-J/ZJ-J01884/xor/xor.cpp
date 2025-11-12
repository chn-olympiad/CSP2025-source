#include<bits/stdc++.h>
using namespace std;
int a[500001],l[500001],r[500001];
int rox(int ll,int rr){
	int x=a[ll];
	for(int i=ll+1;i<=rr;i++){
		x^=a[i];
	}
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,p=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(k==rox(i,j)){
				l[++p]=i;
				r[p]=j;
			}
		}
	}
	int maxn=-1;
	for(int j=1;j<=p;j++){
		int sum=0;
		for(int i=j;i<=p;){
			i=r[i]+1;
			sum++;
		}
		maxn=max(sum,maxn);
	}
	cout<<maxn;	
	return 0;
} 
