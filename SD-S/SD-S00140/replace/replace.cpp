#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
int s[N],ss[N],t[N],tt[N];
struct node{
	int cha,qian,num,ans,lencha,hou;
}a[N],b[N];
bool cmp(node x,node y){
	return x.qian<y.qian;
}
bool cmpp(node x,node y){
	return x.num<y.num;
}
map<pair<int,int>,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string str,strr;
		cin>>str>>strr;
		s[i]=str.find('b');
		ss[i]=strr.find('b');
		a[i].cha=s[i]-ss[i];
		a[i].num=i;
		a[i].qian=s[i];
		a[i].lencha=str.size()-strr.size();
		a[i].hou=str.size()-s[i];
	}
	for(int i=1;i<=q;i++){
		string str,strr;
		cin>>str>>strr;
		t[i]=str.find('b');
		tt[i]=strr.find('b');
		b[i].cha=t[i]-tt[i];
		b[i].num=i;
		b[i].qian=t[i];
		b[i].lencha=str.size()-strr.size();
		b[i].hou=str.size()-t[i];
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+q+1,cmp);
	int l=1;
	for(int i=1;i<=q;i++){
		while(a[l].qian<=b[i].qian&&l<=n){
			mp[{a[l].cha,a[l].lencha}]++;
			l++;
		}
		b[i].ans=mp[{b[i].cha,b[i].lencha}];
	}
	sort(b+1,b+q+1,cmpp);
	for(int i=1;i<=q;i++){
		cout<<b[i].ans<<"\n";
	}
	
	return 0;
}
