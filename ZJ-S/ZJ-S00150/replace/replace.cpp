#include<bits/stdc++.h>
using namespace std;
const int N=2e5+105,M=5e6+105;
string s[N][2],t[N][2];
char txx[M];
struct node{
	string s1,s2,s3,s4;
	int id;
}a[N],b[M];
int cnt1,cnt2,root[N],ans[N];
bool cmp(node xx,node yy){
	if(xx.s1!=yy.s1) return xx.s1<yy.s1;
	if(xx.s2!=yy.s2) return xx.s2<yy.s2;
	if(xx.s3!=yy.s3) return xx.s3<yy.s3;
	if(xx.s4!=yy.s4) return xx.s4<yy.s4;
}
int tree[N+M][26],cntt[N+M],cntx;
void mm(int rt,string s){
	int root=rt;
	for(int i=0;i<s.size();++i){
		if(!tree[root][s[i]-97]) tree[root][s[i]-97]=++cntx;
		root=tree[root][s[i]-97];
	}
	cntt[root]++;
//	cout<<cntt[root]<<endl;
}
int qq(int rt,string s){
	int root=rt,ans1=cntt[rt];
	for(int i=0;i<s.size();++i){
		if(!tree[root][s[i]-97]) break;
		root=tree[root][s[i]-97];
		ans1+=cntt[root];
	}
	return ans1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=0;j<2;++j){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<2;++j){
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		if(s[i][0]==s[i][1]) continue;
		++cnt1;
		a[cnt1].id=i;
		int L,R;
		for(int j=0;j<s[i][0].size();++j){
			if(s[i][1][j]!=s[i][0][j]){
				L=j;
				break;
			}
		}
		for(int j=s[i][0].size()-1;j>=0;--j){
			if(s[i][1][j]!=s[i][0][j]){
				R=j;
				break;
			}
		}
	//	cout<<L<<" "<<R<<endl;
		for(int j=L;j<=R;++j){
			a[cnt1].s1+=s[i][0][j];
			a[cnt1].s2+=s[i][1][j];
		}
		for(int j=L-1;j>=0;--j){
			a[cnt1].s3+=s[i][0][j];
			//a[j].s2+=s[i][1][j];
		}
		for(int j=R+1;j<s[i][0].size();++j){
			a[cnt1].s4+=s[i][0][j];
		}
	}	
	for(int i=1;i<=m;++i){
		if(t[i][0].size()!=t[i][1].size()) continue;
		++cnt2;
		b[cnt2].id=i;
		int L,R;
		for(int j=0;j<t[i][0].size();++j){
			if(t[i][1][j]!=t[i][0][j]){
				L=j;
				break;
			}
		}
		for(int j=t[i][0].size()-1;j>=0;--j){
			if(t[i][1][j]!=t[i][0][j]){
				R=j;
				break;
			}
		}
		for(int j=L;j<=R;++j){
			b[cnt2].s1+=t[i][0][j];
			b[cnt2].s2+=t[i][1][j];
		}
		for(int j=L-1;j>=0;--j){
			b[cnt2].s3+=t[i][0][j];
			//a[j].s2+=s[i][1][j];
		}
		for(int j=R+1;j<t[i][0].size();++j){
			b[cnt2].s4+=t[i][1][j];
		}
	}	
	sort(a+1,a+1+cnt1,cmp);
	sort(b+1,b+1+cnt2,cmp);
	/*for(int i=1;i<=cnt1;++i){
		cout<<a[i].s1<<"#"<<a[i].s2<<"#"<<a[i].s3<<"#"<<a[i].s4<<endl;
	}
	for(int i=1;i<=cnt2;++i){
		cout<<b[i].s1<<"#"<<b[i].s2<<"#"<<b[i].s3<<"#"<<b[i].s4<<endl;
	}*/
	int j=1,l=j;
	while(j<=cnt1&&a[j].s1==a[j+1].s1&&a[j].s2==a[j+1].s2) ++j;
	int r=j;
	bool tt=false;
	for(int i=1;i<=cnt2;++i){
		if(j>cnt1) break;
		if(a[j].s1==b[i].s1&&a[j].s2==b[i].s1){	
			if(!tt){
				for(int k=l;k<=r;++k){
					if(k!=l||a[k].s3!=a[k-1].s3){
						++cntx;
						root[k]=cntx;
						mm(root[k],a[k].s4);
					}
					else{
						root[k]=root[k-1];
						mm(root[k],a[k].s4);
					}
				}
			//	continue;
			}
			tt=true;
			string s5="";
		//	cout<<b[i].s3<<endl;
			int L=l,R=r;
			while(L<=R){
				const int mid=(L+R)>>1;
				if(a[mid].s3<=s5) L=mid+1;
				else R=mid-1;
			}
			if(a[R].s3==s5) ans[b[i].id]+=qq(root[R],b[i].s4);
			for(int k=0;k<b[i].s3.size();++k){
				s5+=b[i].s3[k];
			//	cout<<s5<<endl;
				int L=l,R=r;
				while(L<=R){
					const int mid=(L+R)>>1;
					if(a[mid].s3<=s5) L=mid+1;
					else R=mid-1;
				}
				if(a[R].s3!=s5) continue;
			//	cout<<"EE\n";
				ans[b[i].id]+=qq(root[R],b[i].s4);
			//	cout<<b[i].id<<" "<<ans[b[i].id]<<endl;
			}
		}
		else if(a[j].s1>b[i].s1||(a[j].s1==b[i].s1&&a[j].s2>b[i].s2)){
			continue;
		}
		else{
			while(j<=cnt1&&a[j].s1<b[i].s1||(a[j].s1==b[i].s1&&a[j].s2<b[i].s2)){
				++j;
				tt=false;
			}
			
			l=j;
			while(j<=cnt1&&a[j].s1==a[j+1].s1&&a[j].s2==a[j+1].s2) ++j;
			r=j;
		//	cout<<l<<" "<<r<<" "<<b[i].id<<endl;
		if(j>cnt1||a[j].s1>b[i].s1||(a[j].s1==b[i].s1&&a[j].s2>b[i].s2)) continue; 
			if(!tt){
				for(int k=l;k<=r;++k){
					if(k!=l||a[k].s3!=a[k-1].s3){
						++cntx;
						root[k]=cntx;
						mm(root[k],a[k].s4);
					}
					else{
						root[k]=root[k-1];
						mm(root[k],a[k].s4);
					}
				}
			//	continue;
			}
			tt=true;
			string s5="";
		//	cout<<b[i].s3<<endl;
			int L=l,R=r;
			while(L<=R){
				const int mid=(L+R)>>1;
				if(a[mid].s3<=s5) L=mid+1;
				else R=mid-1;
			}
			if(a[R].s3==s5) ans[b[i].id]+=qq(root[R],b[i].s4);
			for(int k=0;k<b[i].s3.size();++k){
				s5+=b[i].s3[k];
			//	cout<<s5<<endl;
				int L=l,R=r;
				while(L<=R){
					const int mid=(L+R)>>1;
					if(a[mid].s3<=s5) L=mid+1;
					else R=mid-1;
				}
				if(a[R].s3!=s5) continue;
		//		cout<<"EE\n";
		//		return 0;
				ans[b[i].id]+=qq(root[R],b[i].s4);
			}
		}
	}
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
	return 0;
} 
