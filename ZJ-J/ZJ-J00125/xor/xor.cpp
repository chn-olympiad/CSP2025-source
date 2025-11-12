#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],ans;
struct str{
	int x,y;
}s[200005];
bool cmp(str p,str q){
	return p.y<q.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=0,id=0;
	for(int l=1;l<=n;l++){
		b=0;
		for(int r=l;r<=n;r++){
			b=b^a[r];
			if(b==k){
				s[++id].x=l;
				s[id].y=r;
			}
		}
	}
	sort(s+1,s+id+1,cmp);
	int d=0;
	for(int i=1;i<=id;i++){
		if(s[i].x>d){
			ans++;
			d=s[i].y;
		}
	}
	cout<<ans;
	return 0;
}
