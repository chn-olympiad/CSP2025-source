#include<bits/stdc++.h>
using namespace std;
int n,q,mi=100000000;
string s1,s2;
struct k{
	string x,y;
}a[200005];
bool cmp(k a,k b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int find(int key){
	int l=1,r=n;string o=s1.substr(key,mi);
	while(l<=r){
		
		int mid=(l+r)/2;
//		cout<<o<<' '<<a[mid].x<<endl;
		if(a[mid].x>=o){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
//	cout<<l;
	return l;
}
int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace3.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].x.size()<mi)mi=a[i].x.size();
	}
	sort(a+1,a+1+n,cmp);
	while(q--){
		int p=0,sum=0;
		cin>>s1>>s2;
		while(p<=s1.size()-mi){
		//	cout<<1;
			int t=find(p);
		//	cout<<1;
			while(a[t].x.substr(0,mi)==s1.substr(p,mi)){//cout<<s1.substr(0,p)+a[t].y+s1.substr(p+a[t].x.size(),s1.size()-(p+a[t].x.size()));
				if(a[t].x.size()<=s1.size()-p){
					if(a[t].x==s1.substr(p,a[t].x.size())){
//					
					if(s1.substr(0,p)+a[t].y+s1.substr(p+a[t].x.size(),s1.size()-(p+a[t].x.size()))==s2)sum++;}
				}
				t++;
			}
			p++;
			}
		cout<<sum<<endl;
		}
	return 0;
	}
