#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,t,ans=0,id1=0,id2=0,id3=0,tot=0;;
int id[100005];
int a[100005][5];
int b[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,id1=0,id2=0,id3=0;
		for(int i=1;i<=n;i++){
			int maxx=0,pos=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxx){
					maxx=a[i][j];
					pos=j;
				}
			}
			id[i]=pos;
			if(pos==1){
				id1++;
			}
			else if(pos==2){
				id2++;
			}
			else{
				id3++;
			}
			ans+=maxx;
		}
//		cout<<ans<<" "<<id1<<" "<<id2<<" "<<id3<<'\n';
		if(max(id1,max(id2,id3))<=n/2){
			cout<<ans<<'\n';
			continue;
		}
//		cout<<"-1"<<'\n';
		int dq=0,sj=0;
		if(id1>n/2){
			dq=1;
			sj=id1;
		}
		else if(id2>n/2){
			dq=2;
			sj=id2;
		}
		else{
			dq=3;
			sj=id3;
		}
//		cout<<dq<<" "<<sj<<'\n';
		tot=0;
		for(int i=1;i<=n;i++){
			if(id[i]==dq){
//				cout<<"begin:"<<i<<'\n';
				int maxx1=0,maxx2=0;
				for(int j=1;j<=3;j++){
					if(a[i][j]>maxx1){
						maxx2=maxx1;
						maxx1=a[i][j];
					}
					else if(a[i][j]>maxx2){
						maxx2=a[i][j];
					}
				}
//				cout<<maxx1<<" "<<maxx2<<'\n';
				b[++tot]=maxx1-maxx2;
			}
		}
		sort(b+1,b+1+tot);
		for(int i=1;i<=sj-n/2;i++){
			ans-=b[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

