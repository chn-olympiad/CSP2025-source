#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],front[500005],okid[500005],oknum,znum,endtime;
long long ans;
struct zone{
	int start;
	int end;
}z[500005];
int yh(int a,int b){
	int num = 0,t = 0;
	while(a || b){
		if(a%2 != b%2) num += (1<<t);
		t++,a /= 2,b /= 2;
	}
	return num;
}
int fyh(int a,int b){
	int num = 0,t = 0;
	while(a || b){
		if(b%2){
			if(a%2 == 0) num += (1<<t);
		}else{
			if(a%2) num += (1<<t);
		}
		t++,a /= 2,b /= 2;
	}
	return num;
}
bool cmp(zone A,zone B){
	if(A.end != B.end) return A.end < B.end;
	else return A.start < B.start;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(i == 1) front[i] = a[i];
		else front[i] = yh(front[i-1],a[i]);
		if(a[i] == k) okid[++oknum] = i;
	}
	ans = oknum,okid[0] = 0,okid[++oknum] = n+1;
	for(int i = 1;i <= oknum;i++){
		znum = 0;
		for(int j = okid[i-1]+1;j < okid[i];j++){
			if(!a[j]) continue;
			for(int l = j+1;l < okid[i];l++){
				if(fyh(front[j-1],front[l]) == k){
					z[++znum].start = j,z[znum].end = l; 
				}
			}
		}
		sort(z+1,z+znum+1,cmp);
		endtime = z[1].end;
		for(int j = 1;j <= znum;j++){
			if(endtime < z[j].start || j == 1){
				ans++,endtime = z[j].end;
			} 
		}
	}
	printf("%lld",ans);
	return 0;
}
