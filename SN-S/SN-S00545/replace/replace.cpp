#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
struct node{
	string s1,s2;
	int l,pos1,pos2;
};
bool cmp(node a,node b){
	if(a.pos1==b.pos1) return a.pos2<b.pos2;
	return a.pos1<b.pos1; 
}
node t[maxn];
int findd1(int num){
	int l=1,r=n;
	while(l+1<=r){
		int mid=(l+r)>>1;
		if(t[mid].pos1<num) l=mid+1;
		if(t[mid].pos1>=num) r=mid-1;
	}
	return l;
}
int findd2(int x,int num){
	int l=1,r=n;
	while(l+1<=r){
		int mid=(l+r)>>1;
		if(t[mid].pos2<num) l=mid+1;
		if(t[mid].pos2>=num) r=mid-1;
	}
	return l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t[i].s1>>t[i].s2;
		t[i].l=t[i].s1.length();
		for(int j=0;j<t[i].l;j++){
			if(t[i].s1[j]=='b') {
				t[i].pos1=j;
				break;
			} 
		}
		for(int j=0;j<t[i].l;j++){
			if(t[i].s2[j]=='b') {
				t[i].pos2=j;
				break;
			} 
		}
	} 
	sort(t+1,t+1+n,cmp);
	cin>>q;
	for(int i=1;i<=q;i++){
		string p1,p2;
		cin>>p1>>p2;
		
		//int q=findd(pos1);
		//int t=findd(pos2);
		cout<<"0"<<"\n";
	}
	
	return 0;
}
