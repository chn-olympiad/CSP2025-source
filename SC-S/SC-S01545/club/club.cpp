#include<bits/stdc++.h>
using namespace std;

int t,n,m;
struct str{
	int first,second,third;
}a[1000010];
bool sss1(str x,str y){
	return x.first-max(x.second,x.third) < y.first-max(y.second,y.third);
}
bool sss2(str x,str y){
	return x.second-max(x.first,x.third) < y.second-max(y.first,y.third);
}
bool sss3(str x,str y){
	return x.third-max(x.second,x.first) < y.third-max(y.second,y.first);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		m=n/2;
		long long f=0,s=0,th=0,cnt=0;
		for(int i=1;i<=n;i++){
			cin >> a[i].first >> a[i].second >> a[i].third;
			cnt+=max(a[i].first,max(a[i].second,a[i].third));
			if(a[i].first>a[i].second&&a[i].first>a[i].third) f++;
			if(a[i].second>a[i].first&&a[i].second>a[i].third) s++;
			if(a[i].third>a[i].second&&a[i].third>a[i].first) th++;
		}
		if(f<=m&&th<=m&&s<=m){
			cout << cnt << '\n';
			continue;
		}
		if(f>s&&f>th){
			sort(a+1,a+1+n,sss1); 
			for(int i=1,l=1;l<=f-m;i++){
				if(a[i].first>a[i].second&&a[i].first>a[i].third) cnt=cnt-a[i].first+max(a[i].second,a[i].third),l++;
			}
		}
		else if(s>f&&s>th){
			sort(a+1,a+1+n,sss2); 
			for(int i=1,l=1;l<=s-m;i++){
				if(a[i].second>a[i].first&&a[i].second>a[i].third) cnt=cnt-a[i].second+max(a[i].first,a[i].third),l++;
			}
		}
		else if(th>s&&th>f){
			sort(a+1,a+1+n,sss3); 
			for(int i=1,l=1;l<=th-m;i++){
				if(a[i].third>a[i].second&&a[i].third>a[i].first) cnt=cnt-a[i].third+max(a[i].second,a[i].first),l++;
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}
