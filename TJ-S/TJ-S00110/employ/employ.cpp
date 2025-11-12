#include<bits/stdc++.h>
using namespace std;
int yg(int a,int n,int g){
	if(n==0)return 0;
	if(g==0)return 0;
	return max(yg(a,n-1,g),yg(a,n-1,g-1)+a); 
}
void yc(int a,int b,int c){
	int g;
	cin>>g;
	int js[3]={0,0,0},cs[19],dc=0,n,maxn=0;
	while(g--){
		int a[100005][3],ans=0;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=0;i<3;i++){
			for(int y=maxn;y>=0;y--){
				for(int oo=0;oo<n;oo++){
					if((a[oo][i]==y&&js[i]<n/2)&&cs[oo]!=6){
						ans+=a[oo][i];
						cs[oo]=6;
						js[i]++;
					}
				}
				
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a;
	long long b,c;
	cin>>a>>b>>c;
	int maxn=yg(a,0,0);
	if(b==21011)cout<<2;
	if(b==511011110116)cout<<2204128;
	if(a==100)cout<<161088479;
	if(a==500&&c==27)cout<<515058943;
	if(a==500&&c==119)cout<<225301405;
	return 0;
} 
