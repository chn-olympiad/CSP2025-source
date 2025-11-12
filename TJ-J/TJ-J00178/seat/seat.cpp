#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt;
int a[200],s[1010][1010],idx[200];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int tmp=n*m;
	for(int i=1;i<=tmp;i++){
		cin>>a[i];
	}
	int t=a[1];
	bool flag=0;
	int vis=0;
	sort(a+1,a+tmp+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		idx[a[i]]=i;
	}
	int tt=idx[t];
	//cout<<tt<<"\n";
	for(int j=1;j<=m;j++){//ÁÐ 
		if(flag==0){
			for(int i=1;i<=n;i++){//ÐÐ 
				s[j][i]=++cnt;
				if(i==n&&j!=m){
					flag=1;
					break;
				}
			}	
		}
		else if(flag==1){
			for(int i=n;i>=1;i--){
				s[j][i]=++cnt;
				if(i==1&&j!=m){
					flag=0;
					break;
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<s[j][i]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==tt){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
