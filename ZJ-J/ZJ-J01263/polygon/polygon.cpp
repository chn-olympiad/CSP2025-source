#include <bits/stdc++.h>
using namespace std;

int cnt,ans,a[25],Is[25],n;

bool Is_OK(){
	if(cnt==0)return false;
	int temp=0,Max=-1;
	for(int i=1;i<=cnt;i++){
		temp+=a[Is[i]];
		Max=max(Max,a[Is[i]]);
	}
	return temp>2*Max;
}

void DFS(int x){
	if(x>n){
		if(Is_OK())ans=(ans+1)%998244353;
		return;
	}
	
	Is[++cnt]=x;
	DFS(x+1);
	
	cnt--;
	DFS(x+1);
	
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	DFS(1);
	
	printf("%d\n",ans);
	return 0;
}
