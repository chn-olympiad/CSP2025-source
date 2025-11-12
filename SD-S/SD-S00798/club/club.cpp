#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int a[100005][5];
int mp[100005];
int idx1,idx2,idx3;
int t1[100005],t2[100005],t3[100005];
int val[100005];
int ans;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		memset(mp,0,sizeof(mp));
		memset(a,0,sizeof(a));
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		memset(t3,0,sizeof(t3));
		memset(val,0,sizeof(val));
		ans=0;
		idx1=0;idx2=0;idx3=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int tmp=max(max(a[i][1],a[i][2]),a[i][3]);
			if(tmp==a[i][1]){
				mp[i]=1;
				t1[++idx1]=i;
			}
			else if(tmp==a[i][2]){
				mp[i]=2;
				t2[++idx2]=i;
			}
			else {
				mp[i]=3;
				t3[++idx3]=i;
			}
			ans+=tmp;
		}
		int tag=0;
		if(idx1>n/2){
			for(int i=1;i<=idx1;i++){
				val[i]=a[t1[i]][1]-max(a[t1[i]][2],a[t1[i]][3]);
			}
			sort(val+1,val+1+idx1);
			for(int i=1;i<=idx1-n/2;i++){
				ans-=val[i];
			}
		}
		if(idx2>n/2){
	//		cout << "##DEBUG2";
			for(int i=1;i<=idx2;i++){
				val[i]=a[t2[i]][2]-max(a[t2[i]][1],a[t2[i]][3]);
			}
	//		for(int i=1;i<=idx2;i++)cout << val[i] << endl;
			sort(val+1,val+1+idx2);
			for(int i=1;i<=idx2-n/2;i++){
	//			cout << "???";
				ans-=val[i];
			}
		}
		if(idx3>n/2){
	//		cout << "##DEBUG3";
			for(int i=1;i<=idx3;i++){
				val[i]=a[t3[i]][3]-max(a[t3[i]][2],a[t3[i]][1]);
			}
			sort(val+1,val+1+idx3);
			for(int i=1;i<=idx3-n/2;i++){
				ans-=val[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
