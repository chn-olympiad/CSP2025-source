#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t;
int n;
int a[maxn][3];
bool f[maxn]={0};
int p=1;
int ans;
int cnt[6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int l=t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int chao=n/2;
		int n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][2]>a[i][3]){
				if(n1<chao){
					n1++;
					ans+=a[i][1];
				}else if(n2<chao){
					n2++;
					ans+=a[i][2];
				}
			}else if(a[i][1]>a[i][3]&&a[i][3]>a[i][2]){
				if(n1<chao){
					n1++;
					ans+=a[i][1];
				}else if(n3<chao){
					n3++;
					ans+=a[i][3];
				}
			}else if(a[i][2]>a[i][1]&&a[i][1]>a[i][3]){
				if(n2<chao){
					n2++;
					ans+=a[i][2];
				}else if(n1<chao){
					n1++;
					ans+=a[i][1];
				}
			}else if(a[i][2]>a[i][3]&&a[i][3]>a[i][1]){
				if(n2<chao){
					n2++;
					ans+=a[i][2];
				}else if(n3<chao){
					n3++;
					ans+=a[i][3];
				}
			}else if(a[i][3]>a[i][1]&&a[i][1]>a[i][2]){
				if(n3<chao){
					n3++;
					ans+=a[i][3];
				}else if(n1<chao){
					n1++;
					ans+=a[i][1];
				}
			}else if(a[i][3]>a[i][2]&&a[i][2]>a[i][1]){
				if(n3<chao){
					n3++;
					ans+=a[i][3];
				}else if(n2<chao){
					n2++;
					ans+=a[i][2];
				}
			}else if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]){
				ans+=a[i][1];
				int liu=min(n1,min(n2,n3));
				if(liu==n1){
					n1++;
				}else if(liu==n2){
					n2++;
				}else if(liu==n3){
					n3++;
				}
			}else{
				int yu=max(a[i][1],max(a[i][2],a[i][3]));
				if(yu==a[i][1]){
					if(n1<chao){
						n1++;
						ans+=a[i][1];
					}else{
						int han=max(a[i][2],a[i][3]);
						if(han==a[i][2]&&n2<chao){
							n2++;
							ans+=a[i][2];
						}else if(han==a[i][3]&&n3<chao){
							n3++;
							ans+=a[i][3];
						}
					}
				}else if(yu==a[i][2]){
					if(n2<chao){
						n2++;
						ans+=a[i][2];
					}else{
						int han=max(a[i][1],a[i][3]);
						if(han==a[i][1]&&n1<chao){
							n1++;
							ans+=a[i][1];
						}else if(han==a[i][3]&&n3<chao){
							n3++;
							ans+=a[i][3];
						}
					}
				}else if(yu==a[i][3]){
					if(n3<chao){
						n3++;
						ans+=a[i][3];
					}else{
						int han=max(a[i][1],a[i][2]);
						if(han==a[i][1]&&n1<chao){
							n1++;
							ans+=a[i][1];
						}else if(han==a[i][2]&&n2<chao){
							n2++;
							ans+=a[i][2];
						}
					}
				}
			}
		}
		cnt[p]=ans;
		p++;
		n1=0;
		n2=0;
		n3=0;
	}
	for(int i=1;i<=l;i++){
		cout<<cnt[i]<<endl;
	}
	return 0;
}






