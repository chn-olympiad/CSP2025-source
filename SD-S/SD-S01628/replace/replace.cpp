#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
const int N=2e5+5;
int n,q,l,r,len,ans,qq;
map<int,int> flag; 
string s1,s2,t1,t2,tt1,tt2;
struct node{
	string q1,h1;
	string s1,s2;
	int l,ql,hl;
}op[N];
bool cmp(node x,node y){
	if(x.l==y.l){
		return x.s1<y.s1;
	}
	return x.l<y.l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		l=0,r=s1.size()-1;
		if(s1==s2){
			int len=r-l+1;
			op[i].s1=s1.substr(l,len);
			op[i].s2=s2.substr(l,len);
			op[i].l=len;
			continue;
		}
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r]){
			r--;
		}
		len=r-l+1,qq=s1.size();
		op[i].q1=s1.substr(0,l);
		op[i].ql=l;
		op[i].hl=qq-r-1;
		op[i].h1=s1.substr(r+1,qq-r-1); 
		op[i].s1=s1.substr(l,len);
		op[i].s2=s2.substr(l,len);
		op[i].l=len;
	} 
	sort(op+1,op+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(flag[op[i].l]==0){
			flag[op[i].l]=i;
		}
	}
	op[n+1].l=0x3f3f3f3f;
	while(q--){
		cin>>t1>>t2;
		l=0,r=t1.size()-1;
		while(t1[l]==t2[l]){
			l++;
		}
		while(t1[r]==t2[r]){
			r--;
		}
		len=r-l+1;ans=0;
		tt1=t1.substr(l,len);
		tt2=t2.substr(l,len);
		if(flag[len]==0){
			cout<<"0\n";
		}
		else{
			for(int j=flag[len];j<=n;j++){
				if(op[j].s1<tt1){
					continue;
				} 
				if(op[j].s1>tt1){
					break;
				}
				if(op[j].s1==tt1&&op[j].s2==tt2){
					if(op[j].ql>l||op[j].hl>(t1.size()-r-1)){
						continue;
					} 
					if(op[j].ql==0){
						
					}else{
						string qq1=t1.substr(l-op[j].ql,op[j].ql);
						if(op[j].q1!=qq1){
							continue;
						}
					}
					if(op[j].hl==0){
						
					}else{
						string hh1=t1.substr(r+1,op[j].hl);
						if(op[j].h1!=hh1){
							continue;
						}
					}
					ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}/*
*/
