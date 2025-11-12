#include<bits/stdc++.h>
using namespace std;
int t,n;
struct club{
	int ml,ss,uo;
	string gt="hollow";
}a[100010];
priority_queue<club> q;
bool checka(){
	for(int i=1;i<=n;i++){
		if(a[i].ss==a[i].uo&&a[i].ss==0){
			continue;
		}
		return false;
	}
	return true;
}
bool cmpa(club a,club b){
	return a.ml>b.ml;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].ml>>a[i].ss>>a[i].uo;
		}
		if(checka()){
			int ans=0;
			for(int i=1;i<=n;i++){
				q.push(a[i]);
			}
			for(int i=1;i<=n/2;i++){
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<endl;
		}
	}
}
