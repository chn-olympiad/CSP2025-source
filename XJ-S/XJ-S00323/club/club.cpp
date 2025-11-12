#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10;
int t[N][4];
int e[N][4];
int minv[N];
vector<int> pro;
int n;
int ans=0;
vector<int> a,b,c;

bool cmp(int x,int y){
	return x<y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int T;
	cin>>T;
	while(T--){
		ans=0;
		a.clear(),b.clear(),c.clear();
		pro.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t[i][1]>>t[i][2]>>t[i][3];
			int maxv=max({t[i][1],t[i][2],t[i][3]});
			e[i][1]=maxv-t[i][1],e[i][2]=maxv-t[i][2],e[i][3]=maxv-t[i][3];
			if(maxv==t[i][1]){
				a.push_back(i);
				minv[i]=min(e[i][2],e[i][3]);
			}
			else if(maxv==t[i][2]){
				b.push_back(i);
				minv[i]=min(e[i][1],e[i][3]);
			}
			else if(maxv==t[i][3]){
				c.push_back(i);
				minv[i]=min(e[i][2],e[i][1]);
			}
			ans+=maxv;
		}	
		int cnt=a.size();
		pro.clear();
		if(cnt>n/2){
			for(int i=0;i<a.size();i++){
				pro.push_back(minv[a[i]]);
			}
			sort(pro.begin(),pro.end(),cmp);
			int idx=0;
			while(cnt>n/2){
				ans-=pro[idx];
				cnt--;
				idx++;
			}
		}
		cnt=b.size();
		pro.clear();
		if(cnt>n/2){
			for(int i=0;i<b.size();i++){
				pro.push_back(minv[b[i]]);
			}
			sort(pro.begin(),pro.end(),cmp);
			int idx=0;
			while(cnt>n/2){
				ans-=pro[idx];
				cnt--;
				idx++;
			}
		}
		cnt=c.size();
		pro.clear();
		if(cnt>n/2){
			for(int i=0;i<c.size();i++){
				pro.push_back(minv[c[i]]);
			}
			sort(pro.begin(),pro.end(),cmp);
			int idx=0;
			while(cnt>n/2){
				ans-=pro[idx];
				cnt--;
				idx++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
