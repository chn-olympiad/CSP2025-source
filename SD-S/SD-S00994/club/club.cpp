#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define mp make_pair
using namespace std;
const ll N=4e5+10;
const ll INF=1e9;
ll n,x1,x2,x3,i;
struct D{
	priority_queue<PII,vector<PII> >q;
}a[N];
bool cmp1(D w1,D w2){
	if(w1.q.top().second==w2.q.top().second){
		PII s1=w1.q.top();w1.q.pop();PII e1=w1.q.top();w1.q.push(s1);
		PII s2=w2.q.top();w2.q.pop();PII e2=w2.q.top();w2.q.push(s2);
		return s1.first-e1.first>s2.first-e2.first;
	}
	return w1.q.top().second<w2.q.top().second;
}
bool cmp2(D w1,D w2){
	if(w1.q.top().second==w2.q.top().second){
		PII s1=w1.q.top();w1.q.pop();PII e1=w1.q.top();w1.q.push(s1);
		PII s2=w2.q.top();w2.q.pop();PII e2=w2.q.top();w2.q.push(s2);
		return s1.first-e1.first>s2.first-e2.first;
	}
	if(w1.q.top().second==2)return 1;
	else if(w2.q.top().second==2)return 0;
	return 0;
}
bool cmp3(D w1,D w2){
	if(w1.q.top().second==w2.q.top().second){
		PII s1=w1.q.top();w1.q.pop();PII e1=w1.q.top();w1.q.push(s1);
		PII s2=w2.q.top();w2.q.pop();PII e2=w2.q.top();w2.q.push(s2);
		return s1.first-e1.first>s2.first-e2.first;
	}
	return w1.q.top().second>w2.q.top().second;
}
ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=ret*10+ch-48;
		ch=getchar();
	}
	return ret*f;
}
void solve(){
	x1=x2=x3=0;
	n=read();
	for(i=1;i<=n;i++){
		while(a[i].q.size())a[i].q.pop();
		a[i].q.push(mp(read(),1));
		a[i].q.push(mp(read(),2));
		a[i].q.push(mp(read(),3));
	}
	for(i=1;i<=n;i++){
		if(a[i].q.top().second==1)x1++;
		else if(a[i].q.top().second==2)x2++;
		else if(a[i].q.top().second==3)x3++;
	}
	if(2*x1<=n&&2*x2<=n&&2*x3<=n){
		ll sum=0;
		for(i=1;i<=n;i++)sum+=a[i].q.top().first;
		cout<<sum<<"\n";
		return;
	}else if(2*x1>n){
		sort(a+1,a+n+1,cmp1);
		i=n/2+1;
		while(i<=n&&a[i].q.top().second==1){
			a[i].q.pop();
			i++;
		}
		ll sum=0;
		for(i=1;i<=n;i++)sum+=a[i].q.top().first;
		cout<<sum<<"\n";
		return;
	}else if(2*x2>n){
		sort(a+1,a+n+1,cmp2);
		i=n/2+1;
		while(i<=n&&a[i].q.top().second==2){
			a[i].q.pop();
			i++;
		}
		ll sum=0;
		for(i=1;i<=n;i++)sum+=a[i].q.top().first;
		cout<<sum<<"\n";
		return;
		
	}else{
		sort(a+1,a+n+1,cmp3);
		i=n/2+1;
		while(i<=n&&a[i].q.top().second==3){
			a[i].q.pop();
			i++;
		}
		ll sum=0;
		for(i=1;i<=n;i++)sum+=a[i].q.top().first;
		cout<<sum<<"\n";
		return;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll _=read();
 	while(_--){
 		solve();
	}
	return 0; 
}
