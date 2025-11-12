#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][5];
typedef long long ll;
vector<int>x,y,z;
ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
bool cmp1(int u,int v) {
	//对于a前去第二志愿的损失
	int cnt1=a[u][1]-max(a[u][2],a[u][3]);
	//对于b前去第二志愿的损失
	int cnt2=a[v][1]-max(a[v][2],a[v][3]);
	return cnt1>cnt2;
}
bool cmp2(int u,int v) {
	//对于a前去第二志愿的损失
	int cnt1=a[u][2]-max(a[u][1],a[u][3]);
	//对于b前去第二志愿的损失
	int cnt2=a[v][2]-max(a[v][1],a[v][3]);
	return cnt1>cnt2;
}
bool cmp3(int u,int v) {
	//对于a前去第二志愿的损失
	int cnt1=a[u][3]-max(a[u][1],a[u][2]);
	//对于b前去第二志愿的损失
	int cnt2=a[v][3]-max(a[v][1],a[v][2]);
	return cnt1>cnt2;
}
void output() {
	ll res=0;
	for(int i=0; i<x.size(); i++) {
		res+=a[x[i]][1];
	}
	for(int i=0; i<y.size(); i++) {
		res+=a[y[i]][2];
	}
	for(int i=0; i<z.size(); i++) {
		res+=a[z[i]][3];
	}
	printf("%lld\n",res);
}
int dfs(int dep) {
	if(dep==n+1) {
		ll res=0;
		for(int i=0; i<x.size(); i++) {
			res+=a[x[i]][1];
		}
		for(int i=0; i<y.size(); i++) {
			res+=a[y[i]][2];
		}
		for(int i=0; i<z.size(); i++) {
			res+=a[z[i]][3];
		}
		return res;
	}
	x.push_back(dep);
	ll res1=dfs(dep+1);
	x.pop_back();
	
	y.push_back(dep);
	ll res2=dfs(dep+1);
	y.pop_back();
	
	z.push_back(dep);
	ll res3=dfs(dep+1);
	z.pop_back();
	
	return max(res1,max(res2,res3));
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {
		n=read();

		x.resize(0);
		y.resize(0);
		z.resize(0);

		for(int i=1; i<=n; i++) {
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
//		if(n<=30) {
//			printf("%lld\n",dfs(1));
//			continue;
//		}
		//等下改成堆
		for(int i=1; i<=n; i++) {
			if(a[i][1]>=max(a[i][2],a[i][3])) {
				x.push_back(i);
			} else if(a[i][2]>=max(a[i][1],a[i][3])) {
				y.push_back(i);
			} else if(a[i][3]>=max(a[i][1],a[i][2])) {
				z.push_back(i);
			}
		}
		for(int i=1; i<=2.5e6; i++) {
			if(x.size()>=max(y.size(),z.size())) {
				if(x.size()<=n/2) {
					output();
					break;
				} else {
					//排序+转移
					sort(x.begin(),x.end(),cmp1);

					for(int i=(x.size()-n/2)-1; i>=0; i--) {
						if(a[x[i]][2]>=a[x[i]][3]) {
							y.push_back(x[i]);
							x.pop_back();
						} else {
							z.push_back(x[i]);
							x.pop_back();
						}
					}

				}
			}
			if(y.size()>=max(x.size(),z.size())) {
				if(y.size()<=n/2) {
					output();
					break;
				} else {
					sort(y.begin(),y.end(),cmp2);

					for(int i=(y.size()-n/2)-1; i>=0; i--) {
						if(a[y[i]][1]>=a[y[i]][3]) {
							x.push_back(y[i]);
							y.pop_back();
						} else {
							z.push_back(y[i]);
							y.pop_back();
						}
					}

				}
			}
			if(z.size()>=max(y.size(),x.size())) {
				if(z.size()<=n/2) {
					output();
					break;
				} else {
					sort(z.begin(),z.end(),cmp3);

					for(int i=(z.size()-n/2)-1; i>=0; i--) {
						if(a[z[i]][2]>=a[y[i]][3]) {
							y.push_back(z[i]);
							z.pop_back();
						} else {
							x.push_back(z[i]);
							z.pop_back();
						}
					}

				}
			}

//			if(max(x.size(),max(y.size(),z.size()))<=n/2){
//				break;
//			}

		}
		//注意，此时还是不对，因为假设共计10人
		//部门1有第一志愿6人-〉转移为6-1+2=7人
		//部门2有第一志愿4人-〉转移为4+1-2=3人
		//部门3有第一志愿0人
		//那如果部门二的人有第二志愿为部门一的，需要转移至部门三
	}
	return 0;
}