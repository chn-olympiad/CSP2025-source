#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int t,n;

int cnt1,cnt2,cnt3;

pair<int,int> a[N],b[N],c[N];

int d[4][N];

int p[4],vis[N];

bool cmp(pair<int,int> a,pair<int,int> b){return a.first>b.first;}


int ans;

int visa[N],visb[N],visc[N];

void run(int a,int b,int c,int i){
	if(p[a]!=n/2)p[a]++,ans+=d[a][i];
	else if(p[b]!=n/2){
		p[b]++,ans+=d[b][i];
	}
	else{
		p[c]++,ans+=d[c][i];
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(vis,0,sizeof vis);
		p[1]=0;
		p[2]=0;
		p[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].first>>b[i].first>>c[i].first;
			d[1][i]=a[i].first;d[2][i]=b[i].first;d[3][i]=c[i].first;
			if(!d[1][i])cnt1++;
			if(!d[2][i])cnt2++;
			if(!d[3][i])cnt3++;
			b[i].second=c[i].second=a[i].second=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		if(cnt1==cnt2&&cnt1==n){
			for(int i=1;i<=n/2;i++)ans+=c[i].first;
			cout<<ans<<'\n';
			continue;
		}
		else if(cnt1==cnt3&&cnt1==n){
			for(int i=1;i<=n/2;i++)ans+=b[i].first;
			cout<<ans<<'\n';
			continue;
		}
		else if(cnt2==cnt3&&cnt2==n){
			for(int i=1;i<=n/2;i++)ans+=a[i].first;
			cout<<ans<<'\n';
			continue;
		}
		if(cnt1==n){
			for(int i=1;i<=n;i++){
				if(vis[c[i].second]){
					if(d[2][c[i].second]<d[3][c[i].second]){
						ans-=d[2][c[i].second];
						p[2]--;
						p[3]++;
						ans+=d[3][c[i].second];
						vis[c[i].second]=1;
					}
					if(p[2]!=n/2){
						ans+=b[i].first;
						vis[b[i].second]=1;
					}
				}
				else{
					if(c[i].second==b[i].second){
						ans+=max(c[i].first,b[i].first);
						if(c[i].first>b[i].first){
							vis[c[i].second]=1;
							p[3]++;
						}
						else{
							vis[b[i].second]=1;
							p[2]++;
						}
					}
					else{
						if(p[3]!=n/2){ans+=c[i].first;vis[c[i].second]=1;p[3]++;}
						if(p[2]!=n/2){ans+=b[i].first;vis[b[i].second]=1;p[2]++;}
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(cnt2==n){
			for(int i=1;i<=n;i++){
				if(vis[c[i].second]){
					if(d[1][c[i].second]<d[3][c[i].second]){
						ans-=d[1][c[i].second];
						p[1]--;
						p[3]++;
						ans+=d[3][c[i].second];
						vis[c[i].second]=1;
					}
					if(p[1]!=n/2){
						ans+=a[i].first;
						vis[a[i].second]=1;
					}
				}
				else{
					if(a[i].second==c[i].second){
						ans+=max(a[i].first,c[i].first);
						if(a[i].first>c[i].first){
							vis[a[i].second]=1;
							p[1]++;
						}
						else{
							vis[c[i].second]=1;
							p[3]++;
						}
					}
					else{
						if(p[1]!=n/2){ans+=a[i].first;vis[a[i].second]=1;p[1]++;}
						if(p[3]!=n/2){ans+=b[i].first;vis[c[i].second]=1;p[3]++;}
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(cnt3==n){
			for(int i=1;i<=n;i++){
				if(vis[b[i].second]){
					if(d[1][b[i].second]<d[2][b[i].second]){
						//cout<<1111111<<'\n';
						ans-=d[1][b[i].second];
						p[1]--;
						p[2]++;
						ans+=d[2][b[i].second];
						vis[b[i].second]=1;
						//cout<<b[i].second<<' ';
					}
					if(p[1]!=n/2){
						ans+=a[i].first;
						vis[a[i].second]=1;
					}
				}
				else{
					if(a[i].second==b[i].second){
						ans+=max(a[i].first,b[i].first);
						if(a[i].first>b[i].first){
							vis[a[i].second]=1;
							p[1]++;
						}
						else{
							vis[b[i].second]=1;
							p[2]++;
						}
					}
					else{
						if(p[1]!=n/2){ans+=a[i].first;vis[a[i].second]=1;p[1]++;}
						//cout<<a[i].second<<' ';
						if(p[2]!=n/2){ans+=b[i].first;vis[b[i].second]=1;p[2]++;}
						//cout<<b[i].second<<'\n';
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		//cout<<a[1].second<<' '<<b[1].second<<' '<<c[1].second<<'\n';
		bool aa,bb,cc;
		aa=bb=cc=1;
		if(a[1].second==b[1].second){
			vis[a[1].second]=1;aa=bb=0;
			//cout<<a[1].first<<' '<<b[1].first<<' '<<a[1].second<<' '; 
			if(a[1].first>b[1].first){
				p[1]++;
				//cout<<1<<'\n';
			}
			else {
				p[2]++;
				//cout<<2<<'\n';
			}
			ans+=max(a[1].first,b[1].first);
		}
		if(b[1].second==c[2].second){
			vis[b[1].second]=1;bb=cc=0;
			//cout<<b[1].first<<' '<<c[1].first<<' '<<b[1].second<<' '; 
			if(b[1].first>c[1].first){
				p[2]++;//cout<<2<<'\n';
			}
			else {
				p[3]++;
				//cout<<3<<'\n';
			}
			ans+=max(b[1].first,c[1].first);
		}
		if(a[1].second==c[2].second){
			vis[a[1].second]=1;aa=cc=0;
			//cout<<a[1].first<<' '<<c[1].first<<' '<<a[1].second<<' '; 
			if(a[1].first>c[1].first){
				p[1]++;//cout<<1<<'\n';
			}
			else {
				p[3]++;
				//cout<<3<<'\n';
			}
			ans+=max(a[1].first,c[1].first);
		}
		if(aa){
			p[1]++;//cout<<1<<' ';
			vis[a[1].second]=1;
			ans+=a[1].first;
		}
		if(!vis[b[1].second]&&bb){
			p[2]++;//cout<<2<<'\n';
			vis[b[1].second]=1;
			ans+=b[1].first;
		}
		if(!vis[c[1].second]&&cc){
			p[3]++;//cout<<3<<'\n';
			vis[c[1].second]=1;
			ans+=c[1].first;
		}
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(d[1][i]>d[2][i]){
				if(d[2][i]>d[3][i]){
					run(1,2,3,i);
				}
				else if(d[1][i]>d[3][i]){
					run(1,3,2,i);
				}
				else{
					run(3,1,2,i);
				}
			}
			else{
				if(d[2][i]<d[3][i]){
					run(3,2,1,i);
				}
				else if(d[1][i]>d[3][i]){
					run(2,1,3,i);
				}
				else{
					run(2,3,1,i);
				}
			}
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
