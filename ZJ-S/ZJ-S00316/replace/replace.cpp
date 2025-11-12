#include <bits/stdc++.h>
using namespace std;
int n,m,q;
string u,w;
int Idx1,Idx2;
long long ans;
bool vis;
struct node{
	string s1,s2;
	int x,y,z;
}r[200010];
bool cmp(node a, node b){
	if(a.z!=b.z) return a.z < b.z;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> r[i].s1 >> r[i].s2;
		u=r[i].s1,w=r[i].s2;
		r[i].z=r[i].s1.size()-1;
		for(int j=0;j<=r[i].z;j++){
			if(u[j]!=w[j]){
				r[i].x=j;
				break;
			}
		}
		for(int j=max(r[i].z,0);j>=0;j--){
			if(u[j]!=w[j]){
				r[i].y=j;
				break;
			}
		}
//		cout << r[i].x << " " << r[i].y  << endl;
	}
	sort(r+1,r+1+n,cmp);
//	for(int i=1;i<=n;i++) cout << r[i].s1 << "  " << r[i].s2 << endl;
	for(int i=1;i<=q;i++){
		cin >> u >> w;
		Idx1=-1;
		Idx2=-1;
		for(int j=0;j<u.size();j++){
			if(u[j]!=w[j]){
				Idx1=j;
				break;
			}
		}
		int t=u.size()-1;
		for(int j=max(t,0);j>=0;j--){
//			cout << j << endl;
			if(u[j]!=w[j]){
				Idx2=j;
				break;
			}
		}
//		cout << Idx1 << " " << Idx2  << endl;
		if(Idx1==-1) continue;
		ans=0;
		for(int j=1;j<=n;j++){
			if(u.size()>=r[j].z){
				if(r[j].y-r[j].x+1==Idx2-Idx1+1){
					if(Idx1-r[j].x>=0&&u.size()-Idx2>=r[j].z-r[j].y){
						vis=true;
						for(int k=Idx1-r[j].x;k<=Idx2+r[j].z-r[j].y;++k){
//							cout << u[k] << " " << r[j].s1[k] << endl;
							if(u[k]!=r[j].s1[k+r[j].x-Idx1]||w[k]!=r[j].s2[k+r[j].x-Idx1]){
								vis=false;
								break;
							}
						}
						
						if(vis) ans++;
					}
				}
			}
			else break;
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
	




		




