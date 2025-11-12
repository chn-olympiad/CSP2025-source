#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,base,temp,ij,k;
struct st{
	long long d[3],cl;
}s[100005],is;
vector<st> a,b,c,f;
bool cmp(st x,st y){
	if(x.d[x.cl]!=y.d[y.cl]) return x.d[x.cl]>y.d[y.cl];
	if(x.cl==0) return max(x.d[1],x.d[2])>max(y.d[1],y.d[2]);
	if(x.cl==1) return max(x.d[1],x.d[2])>max(y.d[0],y.d[2]);
	if(x.cl==2) return max(x.d[1],x.d[2])>max(y.d[1],y.d[0]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;temp=-1;
		a.clear();b.clear();c.clear();f.clear();
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i].d[0]>>s[i].d[1]>>s[i].d[2];
			base=min(s[i].d[0],min(s[i].d[1],s[i].d[2]));
			s[i].d[0]-=base;
			s[i].d[1]-=base;
			s[i].d[2]-=base;
			ans+=base;
			for(int j=0;j<3;j++){
				if(temp<s[i].d[j]){
					temp=s[i].d[j];
					is=s[i];
					ij=j;
				}
			}
			is.cl=ij;
			if(ij==0) a.push_back(is);
			else if(ij==1) b.push_back(is);
			else c.push_back(is);
			temp=-1;
		}
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		sort(c.begin(),c.end(),cmp);
		for(int i=0;i<min((long long) a.size(),n/2);i++){
			ans+=a[i].d[a[i].cl];
		}
		for(int i=0;i<min((long long) b.size(),n/2);i++){
			ans+=b[i].d[b[i].cl];
		}
		for(int i=0;i<min((long long) c.size(),n/2);i++){
			ans+=c[i].d[c[i].cl];
		}
		k=a.size()-n/2;
		if(k>0){
			for(int i=n/2;i<a.size();i++){
				f.push_back(a[i]);
			}
		}
		k=b.size()-n/2;
		if(k>0){
			for(int i=n/2;i<b.size();i++){
				f.push_back(b[i]);
			}
		}
		k=c.size()-n/2;
		if(k>0){
			for(int i=n/2;i<c.size();i++){
				f.push_back(c[i]);
			}
		}
		for(int i=0;i<f.size();i++){
			for(int j=0;j<3;j++){
				if(j!=f[i].cl){
					temp=max(temp,(long long)f[i].d[j]);
				}
			}
			ans+=temp;
		}
		cout<<ans<<'\n';
	}
}
