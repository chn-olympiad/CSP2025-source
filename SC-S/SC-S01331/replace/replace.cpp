#include<bits/stdc++.h>

#define hyc_qcz_jmr_baoyouwo_AC
#define zty_AK_CSPS_2025

#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fep(i,s,e) for(int i=s;i<e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
#define pef(i,s,e) for(int i=s;i>e;i--)

namespace FastIO{
	template <typename T> inline void read(T &x){
		x=0;
		T f=1;
		T c=getchar();
		for(;!isdigit(c);c=getchar()){
			if(c=='-'){
				f=-1;
			}
		}
		for(;isdigit(c);c=getchar()){
			x=(x<<1)+(x<<3)+(c^48);
		}
		x*=f;
	}
	template <typename T> inline void print(T x){
		if(x<0){
			x=-x;
			putchar('-');
		}
		if(x>9){
			print(x/10);
		}
		putchar((x%10)^48);
	}
}

using namespace std;
using namespace FastIO;
int n,q,id[200005][2],num[2][26],m[200005][2],ans;
unordered_map<int,vector<pair<int,int> > >mp;
string s[200005][2],t[2];
bool flag;
int find_ans(vector<pair<int,int> > v,int tar,int tarr){
	int res=0;
	for(auto i:v){
		if(tar>=i.first&&tarr>=i.second){
			res++;
		}
	}
	return res;
}
void sp(){
	rep(i,1,q){
		rep(j,0,1){
			cin>>t[j];
			m[i][j]=t[j].size();
			fep(k,0,m[i][j]){
				if(t[j][k]=='b'){
					id[i][j]=k;
					break;
				}
			}
		}
//		cout<<id[i][0]<<" "<<id[i][1]<<endl;
		int now=find_ans(mp[id[i][0]-id[i][1]],id[i][0],m[i][0]-id[i][0]-1);
		print(now);
		putchar('\n');
	}
} 
bool check(int id,int st,int len,int llen){
//	cout<<s[id][0]<<" "<<s[id][1]<<" "<<t[0]<<" "<<t[1]<<endl;
	fep(i,0,st){
		if(t[0][i]!=t[1][i]){
			return 0;
		}
	}
	fep(i,0,len){
		rep(j,0,1){
			if(s[id][j][i]!=t[j][i+st]){
				return 0;
			}
		}
	}
	fep(i,len+st,llen){
		if(t[0][i]!=t[1][i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	hyc_qcz_jmr_baoyouwo_AC
	zty_AK_CSPS_2025
//	freopen("replace2.in","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);
	read(q);
	rep(i,1,n){
		rep(j,0,1){
			cin>>s[i][j];
			m[i][j]=s[i][j].size();
			int cnt=0,cntt=0;
			fep(k,0,m[i][j]){
				if(s[i][j][k]=='b'){
					id[i][j]=k;
					cntt++;
				}
				if(s[i][j][k]=='a'){
					cnt++;
				}
			} 
			if(cnt==m[i][j]-1&&cntt==1){
				
			}
			else{
				flag=1;
			}
		}
		mp[id[i][0]-id[i][1]].push_back({id[i][0],m[i][0]-id[i][0]-1});
	}
	if(flag==0){
		sp();
		return 0;
	}
	rep(i,1,q){
//		cout<<i<<endl;
		ans=0;
		rep(j,0,1){
			cin>>t[j];
			m[0][j]=t[j].size();
		}
		rep(j,1,n){
			rep(k,0,m[0][0]-m[j][0]){
//				cout<<j<<" "<<k<<endl;
				if(check(j,k,m[j][0],m[0][0])==1){
					ans++;
//					cout<<"  "<<j<<" "<<k<<endl; 
				}
			}
		}
		print(ans);
		putchar('\n');
	}
	return 0;	
}