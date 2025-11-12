#include<bits/stdc++.h>
using namespace std;
int x[500010];
struct w{
	int xxor,now;
};
vector<w>q;
vector<w>p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int c=0;c<n;c++){
		cin>>x[c];
	}
	int s;
	if(x[0]==k){
		q.push_back({0,1});
		s=1;
	}
	else{
		q.push_back({0,0});
		q.push_back({x[0],0});
		s=2;
	}
	int i=1;
	int z=0;
	while(i<n){
		if(i%2){
			int l=0,r=0;
			for(int c=0;c<s;c++){
				w qq=q[c];
				l=max(qq.now,l);
				if((x[i]^qq.xxor)==k){
					r=max(r,qq.now+1);
				}
				else{
					if((x[i]^qq.xxor)==0){
						continue;
					}
					p.push_back({(x[i]^qq.xxor),qq.now});
					z++;
				}
			}
			p.push_back({0,max(l,r)});
			z++;
			q.clear();
		}
		else{
			int l=0,r=0;
			for(int c=0;c<s;c++){
				w qq=p[c];
				l=max(qq.now,l);
				if((x[i]^qq.xxor)==k){
					r=max(r,qq.now+1);
				}
				else{
					if((x[i]^qq.xxor)==0){
						continue;
					}
					q.push_back({(x[i]^qq.xxor),qq.now});
					z++;
				}
			}
			q.push_back({0,max(l,r)});
			z++;
			p.clear();
		}
		s=z; 
		z=0;
		i++;
	}
	i--;
	int j=0;
	if(i%2){
		for(int c=0;c<s;c++){
			j=max(j,p[c].now);
		}
	}
	else{
		for(int c=0;c<s;c++){
			j=max(j,q[c].now);
		}
	}
	cout<<j;
	return 0;
}