#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=5e5+9;
int n,k;
int a[MAXN];
bool f(int y,int x){
	if(y==x)return a[x]==k;
	int ans=a[x];
	for(int f=x+1;f<=y;f++)
		ans=(ans|a[f]);
	return ans==k;
}
struct ac{
	int start,end;
	ac(int s,int e){start=s,end=e;}
	bool operator<(const ac& v) const{
		return end<v.end;
	}
	bool operator>(const ac& v) const{
		return end>v.end;
	}
};
int main(){
	long long ans=0,l=1;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	vector<ac> wa;
	for(int i=1;i<=n;i++){
		for(int j=l;j<=i;j++){
			if(f(i,j)){
				wa.push_back(ac(j,i));
			}
		}
	}
	sort(wa.begin(),wa.end());
	for(int i=0;i<wa.size();i++){
		ac p=wa[i];
		if(p.start>=l){
			ans++;
			l=p.end+1;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
