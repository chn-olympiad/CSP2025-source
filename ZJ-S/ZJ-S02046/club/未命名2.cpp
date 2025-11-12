#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=2e3+10;
const int inf=1e17;
const int mod=998244353;
int n,k;
int a[N],b[N],c[N];
priority_queue<pii,vector<pii>,greater<pii> > q1,q2,q3; 
int sum1,sum2,sum3;
void solve(){
	sum1=sum2=sum3=0;
	while(!q1.empty()){
		q1.pop();
	}
	while(!q2.empty()){
		q2.pop();
	}
	while(!q3.empty()){
		q3.pop();
	}
	cin>>n;
	k=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=b[i]&&a[i]>=c[i]){
			if(q1.size()==k){
				int j=q1.top().second;
				sum1-=a[j];
				q1.pop();
				int ti=max(b[i],c[i]),tj=max(b[j],c[j]);
				if(sum1+sum2+sum3+a[i]+tj>=sum1+sum2+sum3+a[j]+ti){
					sum1+=a[i];
					q1.push({a[i]-ti,i});
					if(b[j]>=c[j]){
						sum2+=b[j];
						q2.push({b[j]-c[j],j});
					}else{
						sum3+=c[j];
						q3.push({c[j]-b[j],j});
					}
				}else{
					sum1+=a[j];
					q1.push({a[j]-tj,j});
					if(b[i]>=c[i]){
						sum2+=b[i];
						q2.push({b[i]-c[i],i});
					}else{
						sum3+=c[i];
						q3.push({c[i]-b[i],i});
					}
				}
			}else{
				int ti=max(b[i],c[i]);
				sum1+=a[i];
				q1.push({a[i]-ti,i});
			}
		}else if(b[i]>=a[i]&&b[i]>=c[i]){
			if(q2.size()==k){
				int j=q2.top().second;
				sum2-=b[j];
				q2.pop();
				int ti=max(a[i],c[i]),tj=max(a[j],c[j]);
				if(sum1+sum2+sum3+b[i]+tj>=sum1+sum2+sum3+b[j]+ti){
					sum2+=b[i];
					q2.push({b[i]-ti,i});
					if(a[j]>=c[j]){
						sum1+=a[j];
						q1.push({a[j]-c[j],j});
					}else{
						sum3+=c[j];
						q3.push({c[j]-a[j],j});
					}
				}else{
					sum2+=b[j];
					q2.push({b[j]-tj,j});
					if(a[i]>=c[i]){
						sum1+=a[i];
						q1.push({a[i]-c[i],i});
					}else{
						sum3+=c[i];
						q3.push({c[i]-a[i],i});
					}
				}
			}else{
				int ti=max(a[i],c[i]);
				sum2+=b[i];
				q2.push({b[i]-ti,i});
			}
		}else{
			if(q3.size()==k){
				int j=q3.top().second;
				sum3-=c[j];
				q3.pop();
				int ti=max(a[i],b[i]),tj=max(a[j],b[j]);
				if(sum1+sum2+sum3+c[i]+tj>=sum1+sum2+sum3+c[j]+ti){
					sum3+=c[i];
					q3.push({c[i]-ti,i});
					if(a[j]>=b[j]){
						sum1+=a[j];
						q1.push({a[j]-b[j],j});
					}else{
						sum2+=b[j];
						q2.push({b[j]-a[j],j});
					}
				}else{
					sum3+=c[j];
					q3.push({c[j]-tj,j});
					if(a[i]>=b[i]){
						sum1+=a[i];
						q1.push({a[i]-b[i],i});
					}else{
						sum2+=b[i];
						q2.push({b[i]-a[i],i});
					}
				}
			}else{
				int ti=max(a[i],b[i]);
				sum3+=c[i];
				q3.push({c[i]-ti,i});
			}
		}
	}
	cout<<sum1+sum2+sum3<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
