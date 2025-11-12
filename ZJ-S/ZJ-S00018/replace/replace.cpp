#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void init();void Solve();
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;init();
//	cin>>T;
	while(T--) Solve();
	return 0;
}
void init(){
}
#define mod (998244353)
int base=29;
int n,q,len[200005],ans[200005],id[200005],m,sum[200005];
string s[200005][3];
struct node{
	string x,y_1,y_2,z;
	int hshy_1,hshy_2;
	vector<int>hshx,hshy;
}t[200005];
bool check(int x,int y){
	if(t[x].hshy_1!=t[y].hshy_1) return 0;
	if(t[x].hshy_2!=t[y].hshy_2) return 0;
	int len=t[x].hshx.size();
	if(len>0&&(t[y].hshx.size()<len||t[x].hshx[len-1]!=t[y].hshx[len-1])) return 0;
	len=t[x].hshy.size();
	if(len>0&&(t[y].hshy.size()<len||t[x].hshy[len-1]!=t[y].hshy[len-1])) return 0;
	return 1;
}
bool cmp(int x,int y){
	if(check(x,y)) return 1;
	if(t[x].hshy_1!=t[y].hshy_1) return t[x].hshy_1<t[y].hshy_1;
	if(t[x].hshy_2!=t[y].hshy_2) return t[x].hshy_2<t[y].hshy_2;
	if((int)t[x].x.size()!=(int)t[y].x.size()||((int)t[y].hshx.size()>0&&t[x].hshx.back()!=t[y].hshx.back())){
		int l=0,r=min((int)t[x].hshx.size(),(int)t[y].hshx.size())-1,res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(t[x].hshx[mid]==t[y].hshx[mid]){
				res=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		if(res==(int)t[y].hshx.size()-1) return 1;
		if(res==(int)t[x].hshx.size()-1) return 0;
		return t[x].x[res+1]>t[y].x[res+1];
	}
	int l=0,r=min((int)t[x].hshy.size(),(int)t[y].hshy.size())-1,res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(t[x].hshy[mid]==t[y].hshy[mid]){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(res==(int)t[y].hshy.size()-1) return 0;
	if(res==(int)t[x].hshy.size()-1) return 1;
	return t[x].z[res+1]<t[y].z[res+1];
}
bool cmp1(int x,int y){
	if(check(x,y)) return 1;
	if(t[x].hshy_1!=t[y].hshy_1) return t[x].hshy_1<t[y].hshy_1;
	if(t[x].hshy_2!=t[y].hshy_2) return t[x].hshy_2<t[y].hshy_2;
	if((int)t[x].x.size()!=(int)t[y].x.size()||((int)t[y].hshx.size()>0&&t[x].hshx.back()!=t[y].hshx.back())){
		int l=0,r=min((int)t[x].hshx.size(),(int)t[y].hshx.size())-1,res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(t[x].hshx[mid]==t[y].hshx[mid]){
				res=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		if(res==(int)t[y].hshx.size()-1) return 0;
		if(res==(int)t[x].hshx.size()-1) return 1;
		return t[x].x[res+1]>t[y].x[res+1];
	}
	int l=0,r=min((int)t[x].hshy.size(),(int)t[y].hshy.size())-1,res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(t[x].hshy[mid]==t[y].hshy[mid]){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(res==(int)t[y].hshy.size()-1) return 0;
	if(res==(int)t[x].hshy.size()-1) return 1;
	return t[x].z[res+1]<t[y].z[res+1];
}
void Solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()) continue;
		id[++m]=i;
		int len=x.size(),l=1,r=x.size();
		x="#"+x;y="#"+y;
		while(x[l]==y[l]) l++;
		while(x[r]==y[r]) r--;
		for(int j=l-1,o=0;j>=1;j--){
			t[i].x.push_back(x[j]);
			o=(o*base+x[j]-'a'+1)%mod;
			t[i].hshx.push_back(o);
		}
		for(int j=l;j<=r;j++){
			t[i].y_1.push_back(x[j]);
			t[i].y_2.push_back(y[j]);
			t[i].hshy_1=(t[i].hshy_1*base+x[j]-'a'+1)%mod;
			t[i].hshy_2=(t[i].hshy_2*base+y[j]-'a'+1)%mod;
		}
		for(int j=r+1,o=0;j<=len;j++){
			t[i].z.push_back(x[j]);
			o=(o*base+x[j]-'a'+1)%mod;
			t[i].hshy.push_back(o);
		}
	}
	sort(id+1,id+1+m,cmp);
//	for(int i=1;i<=m;i++) cout<<t[id[i]].x<<' '<<t[id[i]].y_1<<' '<<t[id[i]].y_2<<' '<<t[id[i]].z<<endl;
	for(int i=1;i<=n;i++){
		t[q+1].hshx.clear();
		t[q+1].hshy.clear();
		t[q+1].hshy_1=0;
		t[q+1].hshy_2=0;
		t[q+1].x="";
		t[q+1].y_1="";
		t[q+1].y_2="";
		t[q+1].z="";
		string x=s[i][1],y=s[i][2];
		int len=x.size(),l=1,r=x.size();
		x="#"+x;y="#"+y;
		while(x[l]==y[l]) l++;
		while(x[r]==y[r]) r--;
		for(int j=l-1,o=0;j>=1;j--){
			t[q+1].x.push_back(x[j]);
			o=(o*base+x[j]-'a'+1)%mod;
			t[q+1].hshx.push_back(o);
		}
		for(int j=l;j<=r;j++){
			t[q+1].y_1.push_back(x[j]);
			t[q+1].y_2.push_back(y[j]);
			t[q+1].hshy_1=(t[q+1].hshy_1*base+x[j]-'a'+1)%mod;
			t[q+1].hshy_2=(t[q+1].hshy_2*base+y[j]-'a'+1)%mod;
		}
		for(int j=r+1,o=0;j<=len;j++){
			t[q+1].z.push_back(x[j]);
			o=(o*base+x[j]-'a'+1)%mod;
			t[q+1].hshy.push_back(o);
		}
		l=1,r=m;
		int res1=q+1,res2=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(cmp1(q+1,id[mid])){
				res1=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		if(!check(q+1,id[res1])) continue;
		l=res1,r=m;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(q+1,id[mid])){
				res2=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		if(res1>res2) continue;
		sum[res1]++;sum[res2+1]--;
	}
	for(int i=1;i<=m;i++){
		sum[i]+=sum[i-1];
		ans[id[i]]=sum[i];
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}

