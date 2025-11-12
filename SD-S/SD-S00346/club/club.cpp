#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int h[N][4],w[N];
void solve(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>h[i][j];
	if(n==2){
		int maxn=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(j==i)continue;
				maxn=max(maxn,h[1][i]+h[2][j]);
			}
		}
		cout<<maxn<<"\n";
		return ;
	}
	if(n==4){
		int maxn=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(i==j&&j==k)continue;
					for(int l=1;l<=3;l++){
						if(i==j&&j==l)continue;
						if(i==k&&k==l)continue;
						if(j==k&&k==l)continue;
						maxn=max(maxn,h[1][i]+h[2][j]+h[3][k]+h[4][l]);
					}
				}
			}
		}
		cout<<maxn<<"\n";
		return ;
	}
	if(n==10){
		int maxn=0,s[4]={0,0,0,0};
		for(int i0=1;i0<=3;i0++){
			s[i0]++;
			for(int i1=1;i1<=3;i1++){
				s[i1]++;
				for(int i2=1;i2<=3;i2++){
					s[i2]++;
					for(int i3=1;i3<=3;i3++){
						s[i3]++;
						for(int i4=1;i4<=3;i4++){
							s[i4]++;
							for(int i5=1;i5<=3;i5++){
								s[i5]++;
								for(int i6=1;i6<=3;i6++){
									s[i6]++;
									for(int i7=1;i7<=3;i7++){
										s[i7]++;
										for(int i8=1;i8<=3;i8++){
											s[i8]++;
											for(int i9=1;i9<=3;i9++){
												s[i9]++;
												if(s[1]>5||s[2]>5||s[3]>5){
													s[i9]--;
													continue;
												}
												maxn=max(maxn,h[1][i0]+h[2][i1]+h[3][i2]+h[4][i3]+h[5][i4]+h[6][i5]+h[7][i6]+h[8][i7]+h[9][i8]+h[10][i9]);
												s[i9]--;
											}
											s[i8]--;
										}
										s[i7]--;
									}
									s[i6]--;
								}
								s[i5]--;
							}
							s[i4]--;
						}
						s[i3]--;
					}
					s[i2]--;
				}
				s[i1]--;
			}
			s[i0]--;
		}
		cout<<maxn<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++)w[i]=h[i][1];
	sort(w+1,w+n+1);
	for(int i=n/2;i<=n;i++)ans+=w[i];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
