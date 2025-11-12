#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,t;
int cy[500005][5];
long long ans;
struct t0b{
	int c,num;
}ann[500005];
bool cmp1(int x,int y){
	return x>y;
}
bool cmp2(t0b x,t0b y){
	return x.c>y.c;
}
void dfs(int k,long long an,int a,int b,int c){
	if(k==n+1){
		ans=max(ans,an);
		return ;
	}
	if(a<n/2) dfs(k+1,an+cy[k][1],a+1,b,c);
	if(b<n/2) dfs(k+1,an+cy[k][2],a,b+1,c);
	if(c<n/2) dfs(k+1,an+cy[k][3],a,b,c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(ann,0,sizeof(ann));
		cin>>n;
		int A=1,B=1;
		for(int i=1;i<=n;i++){
			cin>>cy[i][1]>>cy[i][2]>>cy[i][3];
			if(cy[i][2]!=0||cy[i][3]!=0) A=0;
			if(cy[i][3]!=0) B=0; 
		}
		if(A){
			int an[500005];
			memset(an,0,sizeof(an));
			for(int i=1;i<=n;i++){
				an[i]=cy[i][1];
			}
			sort(an+1,an+n+1,cmp1);
			for(int i=1;i<=(n/2);i++){
				ans+=an[i];
			}
			cout<<ans<<endl;
		}
		else if(B){
			int a=0,b=0; 
			for(int i=1;i<=n;i++){
				ann[i].c=abs(cy[i][1]-cy[i][2]);
				ann[i].num=i;
			}
			sort(ann+1,ann+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if((cy[ann[i].num][1]>cy[ann[i].num][2]&&a<(n/2))||b==(n/2)){
					ans+=cy[ann[i].num][1];
					a++;
				}
				else{
					ans+=cy[ann[i].num][2];
					b++;
				}
			}
			cout<<ans<<endl;
		}
		else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}

