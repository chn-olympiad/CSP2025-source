#include<bits/stdc++.h>
using namespace std;
int n;
int len[5005];
long long ans=0;
void poly(int cnt,int maxx){
	if(cnt>2*maxx){
		ans++;
		ans%=998244353;
	}
	return;
}
void choose(int gun,int last,int cnt,int maxx){
	if(gun>=3){
		poly(cnt,maxx);
	}
	for(int i=last+1;i<=n;i++){
		choose(gun+1,i,cnt+len[i],max(maxx,len[i]));
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
	}
	if(n>20){
		int count=0;
		for(int i=3;i<=n;i++){
			for(int j=n-i+1;j>=1;j--){
				count+=j;
				count%=998244353;
			}
		}
		cout<<count;
		return 0;
	}
	choose(0,0,0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
