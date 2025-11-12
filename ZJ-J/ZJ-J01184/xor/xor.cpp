#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,l[500005];
struct p{
	int x,y;
};
bool cmp(p b,p c){
	if(b.y!=c.y)return b.y<c.y;
	return b.x<c.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	vector<p>a;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&l[i]);
	for(int i=0;i<n;i++){
		int s=0;
		for(int j=i;j<n;j++){
			s^=l[j];
			if(s==k){
				a.push_back({i,j});
				break;
			}
		}
	}
	sort(a.begin(),a.end(),cmp);
	int ans=1,e=a[0].y;
	for(int i=1;i<a.size();i++){
		if(a[i].x>e){
			ans++;
			e=a[i].y;
		}
	}
	printf("%d\n",ans);
	return 0;
}

