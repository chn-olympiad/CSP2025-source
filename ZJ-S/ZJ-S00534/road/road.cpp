#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
ll b[100];
ll w[20][10010];
int f[100010];
int ans;
vector<ll> va[100010],vb[100010];
ll minn=INT_MAX;
int rd[100010];
int a[10010][10010];
struct node{
	ll x,y,s;
}bian[2000010];
ll sum;
int dan[20010];
int find(int xx){
	if(xx==f[xx]) return xx;
	return f[xx]=find(f[xx]);
}
bool cmp(node s1,node s2){
	return s1.s<s2.s;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>bian[i].x>>bian[i].y>>bian[i].s;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	sort(bian+1,bian+1+m,cmp);
	for(int i=1;i<=m;i++){
		int s1=find(bian[i].x),s2=find(bian[i].y);
		if(s1!=s2){
		    va[bian[i].x].push_back(bian[i].y);
		    vb[bian[i].x].push_back(bian[i].s);
		    va[bian[i].y].push_back(bian[i].x);
		    vb[bian[i].y].push_back(bian[i].s);
			f[s1]=s2;
			sum+=bian[i].s;
		}
	}
	if(k==0){
		cout<<sum;
		return 0;
	}
//	cout<<sum<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<va[i].size();j++){
			ll s1=va[i][j];
			ll s2=vb[i][j];
			if(rd[i]&&rd[s1]) continue;
			int minn=INT_MAX;
		    int mxb=-1;
			for(int l=1;l<=k;l++){
//				ans++;
//				cout<<ans<<endl;
                ll ss=b[l]+w[l][i]+w[l][s1];
//                ll sss=ss;
//                cout<<ss<<endl;
                if(rd[i]){
                	ss-=w[l][i];
				}
				if(rd[s1]){
					ss-=w[l][s1];
				}
				if(s2>ss){
//					cout<<sss<<endl;
//					cout<<s2<<" "<<ss<<endl;
//                    cout<<b[l]<<"  "<<w[l][i]<<" "<<w[l][s1]<<endl;
					if(minn>ss){
						minn=ss;
						mxb=l;
					}
				}
			}
			if(mxb!=-1){
//				cout<<i<<"  "<<mxb<<"  "<<s1<<endl;
                rd[i]=1;
                rd[s1]=1;
				b[mxb]=0;
				sum=sum-s2+minn;
			}
			
		}
	}
	cout<<sum;
	return 0;
}
