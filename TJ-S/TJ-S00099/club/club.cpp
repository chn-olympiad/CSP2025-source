#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a[100005],b[100005],c[100005],a1[100005],b1[100005],c1[100005],a2=0,b2=0,c2=0,cnt=0;
	int n,ans=0;
	int T;
	bool bu=false,ru=false;
	cin>>T;
	while(T--){
		cin>>n;
		cnt=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			a1[i]=a[i],b1[i]=b[i],c1[i]=c[i];
		}for(int i=0;i<n;i++){
			ans=max(ans,a[i]),ans=max(ans,b[i]),ans=max(ans,c[i]);
			
			if(ans==a[i]&&a2+1<=n/2){
				sort(a1,a1+n);
				for(int j=n-1;j>=n/2;j--){
					if(a1[j]==a[i]){
						a2++;
						cnt+=a[i];
						bu=true;
						break;
					}
				}if(bu){
					bu=false;
					continue;
				}else ru=true;	
			}
			else if(ans==b[i]&&b2+1<=n/2){
				sort(b1,b1+n);
				for(int j=n-1;j>=n/2;j--){
					if(b1[j]==b[i]){
						b2++;
						cnt+=b[i];
						bu=true;
						break;
					}
				}if(bu){
					bu=false;
					continue;
				}else ru=true;
			}
			else if(ans==c[i]&&c2+1<=n/2){
				sort(c1,c1+n);
				for(int j=n-1;j>=n/2;j--){
					if(c1[j]==c[i]){
						c2++;
						cnt+=c[i];
						bu=true;
						break;
					}
				}if(bu){
					bu=false;
					continue;
				}else ru=true;
			}else if(a2==n/2||ru){
				ru=false;
				ans=0;
				ans=max(b[i],c[i]);
				if(ans==b[i]){
					sort(b1,b1+n);
					for(int j=n-1;j>=n/2;j--){
						if(b1[j]==b[i]){
							b2++;
							cnt+=b[i];
							bu=true;
							break;
						}
					}if(bu){
						bu=false;
						continue;
					}
				}else if(ans>=c[i]){
					sort(c1,c1+n);
					for(int j=n-1;j>=n/2;j--){
						if(c1[j]==c[i]){
							c2++;
							cnt+=c[i];
							bu=true;
							break;
						}
					}if(bu){
						bu=false;
						continue;
					}
				}
			}else if(b2>=n/2||ru){
				ru=false;
				ans=0;
				ans=max(a[i],c[i]);
				if(ans==a[i]){
					sort(a1,a1+n);
					for(int j=n-1;j>=n/2;j--){
						if(a1[j]==a[i]){
							a2++;
							cnt+=a[i];
							bu=true;
							break;
						}
					}if(bu){
						bu=false;
						continue;
					}
				}else if(ans==c[i]){
					sort(c1,c1+n);
					for(int j=n-1;j>=n/2;j--){
						if(c1[j]==c[i]){
							c2++;
							cnt+=c[i];
							bu=true;
							break;
						}
					}if(bu){
						bu=false;
						continue;
					}
				}
			}else if(c2>=n/2||ru){
				ru=false;
				ans=0;
				ans=max(a[i],b[i]);
				if(ans==a[i]){
					sort(a1,a1+n);
					for(int j=n-1;j>=n/2;j--){
						if(a1[j]==a[i]){
							a2++;
							cnt+=a[i];
							bu=true;
							break;
						}
					}if(bu){
						bu=false;
						continue;
					}
				}else if(ans==b[i]){
					sort(b1,b1+n);
					for(int j=n-1;j>=n/2;j--){
						if(b1[j]==b[i]){
							b2++;
							cnt+=b[i];
							bu=true;
							break;
						}
					}if(bu){
						bu=false;
						continue;
					}
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
} 
