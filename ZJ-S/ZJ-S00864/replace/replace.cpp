#include<bits/stdc++.h>
using namespace std;
long long n,q,len,kkk,ans,ll,rr,lplo[5000010];
string a[200010],b[200010],x[1010][1010],y[1010][1010],s,t;
unordered_map<string,long long> visl;
unordered_map<string,long long> visr;
long long as(long long plplpl){
	if(x>0) return plplpl;
	return -plplpl;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n*n*q<=1000000000&&n<=1000&&q<=1000){
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			visl[a[i]]=i;
			visr[b[i]]=i;
		}
		while(q--){
			ans=0;
			ll=0;
			cin>>s>>t;
			string l,lolo;
			while(s[ll]==t[ll]) ll++;
			rr=s.size()-1;
			while(s[rr]==t[rr]) rr--; 
			for(long long i=ll;i<=rr;i++) l=l+s[i];
			for(long long i=ll;i<=rr;i++) lolo=lolo+t[i];
			len=s.size();
			string qp,pq;
			qp=l;
			for(long long i=ll;i>=1;i--){
				pq=qp;
				qp=s[i-1]+qp;
				for(long long j=rr;j<len-1;j++){
					x[i][j]=pq;
					pq=pq+s[j+1];
				}
				x[i][len-1]=pq;
			}
			pq=qp;
			for(long long j=rr;j<len-1;j++){
				x[0][j]=pq;
				pq=pq+s[j+1];
			}
			x[0][len-1]=pq;
			qp=lolo;
			for(long long i=ll;i>=1;i--){
				pq=qp;
				qp=t[i-1]+qp;
				for(long long j=rr;j<len-1;j++){
					y[i][j]=pq;
					pq=pq+t[j+1];
				}
				y[i][len-1]=pq;
			}
			pq=qp;
			for(long long j=rr;j<len-1;j++){
				y[0][j]=pq;
				pq=pq+t[j+1];
			}
			y[0][len-1]=pq;
			for(long long i=0;i<=ll;i++){
				for(long long j=rr;j<len;j++){
					if(visl[x[i][j]]==visr[y[i][j]]&&visl[x[i][j]]!=0){
						ans++;
					} 
				}
			}
			cout<<ans<<"\n";
		}
	}
	else{
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			lplo[as(a[i].find("b")-b[i].find("b"))]++;
		}
		while(q--){
			cin>>s>>t;
			cout<<lplo[as(s.find("b")-t.find("b"))]<<"\n";
		}
	}
}