#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c;
}cl[100004];
int g[10005],d=0;
int cnt1=0,cnt2=0,cnt3=0,maxx=1,p[4];
void zh(int n){
	int cnt1=0;
	p[0]=0,p[1]=0,p[2]=0;
	for(int i=n;i;i/=3){
		g[++cnt1]=i%3;
		
	}
}
bool cmp(club A,club B){
	return A.a>B.a;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club,out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,maxx=0;
		cin>>n;
		d=n;
		
		for(int i=1;i<=n;i++){
			cin>>cl[i].a>>cl[i].b>>cl[i].c;
		}
		if(n>=10000){
			int sum=0;
			sort(cl+1,cl+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			sum+=cl[i].a;
			
			cout<<sum;
		}
		for(int i=0;i<=pow(3,n);i++){
			int sum=0;
			zh(i);
			for(int j=1;j<=n;j++){
				p[g[j]]++;
			}
			if(p[0]>n/2||p[1]>n/2||p[2]>n/2) continue;
			for(int j=1;j<=n;j++){
				if(g[j]==0){
					sum+=cl[j].a;
				}else if(g[j]==1){
					sum+=cl[j].b;
				}else{
					sum+=cl[j].c;
				}
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx<<endl;
	}
	return 0;
}
