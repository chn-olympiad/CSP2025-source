#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500009],st[500009];
struct Node{
	int x,y;
};
vector<Node>v;
bool nun(int l,int r){
	int m;
	if(l==1) m=st[r];
	else m=st[r]^st[l-1];
	if(m==k) return true;
	else return false;
}
bool cmp(Node a,Node b){
	return a.y<b.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(i==1) st[i]=a[i];
		else st[i]=st[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(nun(j,i)){
				Node p;
				p.x=j,p.y=i;
				v.push_back(p);
			}
		}
	}
	int t=0;
	long long ri=0;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(ri<v[i].x){
			ri=v[i].y;
			t++;
		}
	}
	cout<<t;
	return 0;
}

