#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a,f[10020],bfn[20],w[20];
long long d,dd;
pair<int,int> b2[20][10010];
pair<int,pair<int,int>> b[1000010],bf[20][10020];
int gt(int k){
	if(f[k]<0)
		return k;
	return f[k]=gt(f[k]);
}
void qj(int k,int lk,long long dd2){
	if(k>a)
		return;
	qj(k+1,lk,dd2);
	long long dd=dd2+w[k];
	for(int i=1;i<=n+k;i++)
		f[i]=-1;
	bfn[k]=0;
	for(int i1=1,i2=1;i1<=bfn[lk] || i2<=n;){
		if(i2>n || i1<=bfn[lk] && bf[lk][i1].first<=b2[k][i2].first){
			int z1=gt(bf[lk][i1].second.first),z2=gt(bf[lk][i1].second.second);
			if(z1==z2){
				i1++;
				continue;
			}
			bf[k][++bfn[k]]=bf[lk][i1];
			dd+=bf[lk][i1].first;
			if(f[z1]>f[z2])
				swap(z1,z2);
			f[z1]+=f[z2];
			f[z2]=z1;
			i1++;
		}
		else{
			int z1=gt(n+k),z2=gt(b2[k][i2].second);
			if(z1==z2){
				i2++;
				continue;
			}
			bf[k][++bfn[k]]={b2[k][i2].first,{n+k,b2[k][i2].second}};
			dd+=b2[k][i2].first;
			if(f[z1]>f[z2])
				swap(z1,z2);
			f[z1]+=f[z2];
			f[z2]=z1;
			i2++;
		}
	}
	d=min(d,dd);
	qj(k+1,k,dd2+w[k]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>a;
	for(int i=1;i<=m;i++)
		cin>>b[i].second.first>>b[i].second.second>>b[i].first;
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
		f[i]=-1;
	for(int i=1;i<=m;i++){
		int z1=gt(b[i].second.first),z2=gt(b[i].second.second);
		if(z1==z2)
			continue;
		bf[0][++bfn[0]]=b[i];
		if(f[z1]>f[z2])
			swap(z1,z2);
		f[z1]+=f[z2];
		f[z2]=z1;
		d+=b[i].first;
	}
	for(int i=1;i<=a;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			cin>>b2[i][j].first;
			b2[i][j].second=j;
		}
		sort(b2[i]+1,b2[i]+n+1);
	}
	qj(1,0,0);
	cout<<d;
	return 0;
}
