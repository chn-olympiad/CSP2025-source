#include<bits/stdc++.h>
using namespace std;
struct road{
	int d1,d2,mn,fr;
}r[1001];
struct village{
	int mn,t[1001];
}v[1001];
int n,m,k,p1,p;
int li[1001];
bool cmp(road x,road y){
	return x.mn<y.mn;
}
queue<road> q;
queue<road> tmp;
int ck2(int i,int j){
	tmp=q;
	while(!tmp.empty()){
		int d11=tmp.front().d1,d12=tmp.front().d2;
		if(d11==i&&d12==j){
			return 1;
		}
	}
	return 0;
}
int ck1(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)continue;
			if(!ck2(i,j))return 0;
		}
	}
	return 1;
}
int main(){
	cin>>n>>m>>k;
	m*=2;
	for(int i=0;i<m;i+=2){
		cin>>r[i].d1>>r[i].d2>>r[i].mn;
		r[i+1].d1=r[i].d2,r[i+1].d2=r[i].d1;r[i+1].mn=r[i].mn;
		r[i].fr=r[i+1].fr=0;
	}
	for(int i=0;i<k;i++){
		cin>>v[i].mn;
		for(int j=0;j<n;j++){
			cin>>v[i].t[j];
		}
	}
	p=m;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			r[p].d1=n+k,r[p].d2=j,r[p].mn=v[i].t[j];
			r[p+1].d2=n+k,r[p+1].d1=j,r[p+1].mn=v[i].t[j];
			r[p].fr=r[p+1].fr=k+1;
			p+=2;
		}
	}
	n+=k;
	sort(r,r+p,cmp);
	int ans;
	while(!ck1()){
		q.push(r[p1]);
		q.push(r[p1+1]);
		if(r[p1].fr=0){
			ans+=r[p1].mn;
		}else{
			ans+=r[p1].mn;
			if(li[r[p1].fr]==0){
				ans+=v[r[p1].fr-1].mn;
			}
		}
	}
	cout<<ans;
	return 0;
}