#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100009],b[100009],c[100009];
int on,tw,th;
int answer=0;
void A(){
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n/2;i++){
		answer+=a[i];
	}
	return;
}
void dfs(int step,int coun){
	if(on>n/2||tw>n/2||th>n/2){
		return;
	}
	if(step==n){
		answer=max(answer,coun);
		return;
	}
	on++;
	dfs(step+1,coun+a[step+1]);
	on--;
	tw++;
	dfs(step+1,coun+b[step+1]);
	tw--;
	th++;
	dfs(step+1,coun+c[step+1]);
	th--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		on=0;
		th=0;
		tw=0;
		scanf("%d",&n);
		bool flag=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(b[i]!=0||c[i]!=0){
				flag=1;
			}
		}
		if(flag==0){
			A();
		}
		else{
			dfs(0,0);
		}
		printf("%d\n",answer);
		answer=-1;
	}
} 
