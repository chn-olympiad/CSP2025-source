//SN-J00661 樊仕博 华阴市城关初级中学
#include<bits/stdc++.h>
using namespace std;

int n;
int k;
int a[500001];
int cnt,ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans=ans xor a[i];
		if(ans==k){
			cnt++;
			ans=0;
		}
	}
	printf("%d",cnt);
	return 0;
}
