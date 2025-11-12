#include<bits/stdc++.h>
#define sz size()
#define fs first
#define sc second
#define fst ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n;
struct Shiro{
	int a,b,c;
	int mx;
}x[100100];
int d[4][100100],ta=0,tb=0,tc=0;
int cha[4][20100];
long long ans=0;
void qk(){
	ans=0;
	ta=0;
	tb=0;
	tc=0;
	for(int i=1;i<=3;i++){
		for(int j=0;j<=20000;j++){
			cha[i][j]=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	fst;
	int t;
	cin>>t;
	while(t--){
		qk();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			int maxx=max(max(x[i].a,x[i].b),x[i].c);
			if(maxx==x[i].a){
				ta++;
				d[1][ta]=i;
				cha[1][min(x[i].a-x[i].b,x[i].a-x[i].c)]++;
			}else if(maxx==x[i].b){
				tb++;
				d[2][tb]=i;
				cha[2][min(x[i].b-x[i].a,x[i].b-x[i].c)]++;
			}else if(maxx==x[i].c){
				tc++;
				d[3][tc]=i;
				cha[3][min(x[i].c-x[i].a,x[i].c-x[i].b)]++;
			}ans+=maxx;
		}//cout<<ta<<" "<<tb<<" "<<tc<<endl;
		if(ta<=n/2&&tb<=n/2&&tc<=n/2){
			cout<<ans<<endl;
			continue;
		}else{
			int chao=max(ta,max(tb,tc));
			if(chao==ta){
				for(int i=0;i<=20000;i++){
					if(cha[1][i]!=0){
						if(ta-cha[1][i]>n/2){
							ta-=cha[1][i];
							ans-=cha[1][i]*i;
						}else if(ta-cha[1][i]<=n/2){
							int m=ta-n/2;
							ans-=m*i;
							break;
						}
					}
				}
			}else if(chao==tb){
				for(int i=0;i<=20000;i++){
					if(cha[2][i]!=0){
						if(tb-cha[2][i]>n/2){
							tb-=cha[2][i];
							ans-=cha[2][i]*i;
						}else if(tb-cha[2][i]<=n/2){
							int m=tb-n/2;
							ans-=m*i;
							break;
						}
					}
				}
			}else if(chao==tc){
				for(int i=0;i<=20000;i++){
					if(cha[3][i]!=0){
						if(tc-cha[3][i]>n/2){
							tc-=cha[3][i];
							ans-=cha[3][i]*i;
						}else if(tc-cha[3][i]<=n/2){
							int m=tc-n/2;
							ans-=m*i;
							break;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
// finish time(do+check) 15:18
// wo pang bian de da lao 14:46 ba zhe dao ti miao le QAQ
