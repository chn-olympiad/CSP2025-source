#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(b);i>=(a);i--)
using namespace std;
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
typedef long long ll;
const int N=1e5+5;
string s1[N],s2[N];
string t1[N],t2[N];
ll n,q;
int flag=0;//xabcx5  xadex5   xabcx5      xadex5
int minstr[N]; 
int solve(string a,string b,string c,string d){
	int ans=0;
	rep(i,0,c.size()-1){
		if(c[i]==a[0]){//是否包含 
//			if(a.size()<=mins) continue;
			flag=0;
			rep(j,0,a.size()-1){//包含检验 
				if(c.size()-i<a.size()) break;
				if(!(c[i+j]==a[j])){
					flag=0;
					break;
					
				}
				flag=1;
			}
			if(flag==1){//包含则替换 
//				cout<<a<<' '<<i<<endl;
				string c2;c2=c;
				rep(j,0,b.size()-1){//替换 
					c2[i+j]=b[j];
				}
//				cout<<c2<<endl;
				flag=0;
				rep(j,0,c.size()-1){//检查是否相等 
					if(c2[j]!=d[j]){
						flag=0;
						break;
					}
					flag=1;
				}
				if(flag) ans++;//相等加一
				flag=0; 
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	rep(i,1,n){
		cin>>s1[i]>>s2[i];
	}
	int cnt=0;
	rep(i,1,q){
		cnt=0;
		cin>>t1[i]>>t2[i];
//		int st=0x3f3f3f,ed=0;
//		rep(j,0,t1[i].size()-1){
//			if(!(t1[i][j]==t2[i][j])){
//				st=min(j,st);
//				ed=max(j,ed);
//			}
//			minstr[i]=ed-st+1;
//		}
		rep(j,1,n){
			cnt+=solve(s1[j],s2[j],t1[i],t2[i]);
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

