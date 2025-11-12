#include<bits/stdc++.h>
using namespace std;
int n,t,cnt[3],ans,maxp;
struct stu{
	int arr[3],tofir,tosec,tolst,fir,sec,lst;
}a[100005];
int main(){
	ifstream cin("club.in");
	ofstream cout("club.out");
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof cnt);
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].arr[0]>>a[i].arr[1]>>a[i].arr[2];
			if(a[i].arr[0]>=a[i].arr[1]&&a[i].arr[1]>=a[i].arr[2]){
				a[i].fir=0;
				a[i].sec=1;
				a[i].lst=2;
			}else if(a[i].arr[0]>=a[i].arr[2]&&a[i].arr[2]>=a[i].arr[1]){
				a[i].fir=0;
				a[i].sec=2;
				a[i].lst=1;
			}else if(a[i].arr[1]>=a[i].arr[0]&&a[i].arr[0]>=a[i].arr[2]){
				a[i].fir=1;
				a[i].sec=0;
				a[i].lst=2;
			}else if(a[i].arr[1]>=a[i].arr[2]&&a[i].arr[2]>=a[i].arr[0]){
				a[i].fir=1;
				a[i].sec=2;
				a[i].lst=0;
			}else if(a[i].arr[2]>=a[i].arr[0]&&a[i].arr[0]>=a[i].arr[1]){
				a[i].fir=2;
				a[i].sec=0;
				a[i].lst=1;
			}else{
				a[i].fir=2;
				a[i].sec=1;
				a[i].lst=0;
			}
			a[i].tofir=a[i].arr[a[i].fir]-a[i].arr[a[i].fir];
			a[i].tosec=a[i].arr[a[i].fir]-a[i].arr[a[i].sec];
			a[i].tolst=a[i].arr[a[i].fir]-a[i].arr[a[i].lst];
			cnt[a[i].fir]++;
			ans+=a[i].arr[a[i].fir];
		}
		maxp=max_element(cnt,cnt+3)-cnt;
		if(cnt[maxp]<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		sort(a,a+n,[](stu& a,stu& b){return a.tosec<b.tosec;});
		for(int i=0;i<n&&cnt[maxp]>n/2;i++){
			if(a[i].fir==maxp){
				cnt[maxp]--;
				cnt[a[i].sec]++;
				ans-=a[i].tosec;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
10000 9999 0
0 100 0
0 100 0
0 100 0
*/
