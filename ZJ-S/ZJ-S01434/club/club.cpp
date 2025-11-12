#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll tmp1, tmp2, tmp3;
ll tmplst[5];
struct peo{
	ll g1, g2, g3;
	ll div; //满意度1,2差值 
	ll maxg; //最高满意度 
}pl[100010];
bool cmp(peo a, peo b){
	if(a.div==b.div) a.maxg > b.maxg;
	else return a.div > b.div;
}
int comp(ll s1, ll s2, ll s3){
	if(s1>s2 && s1>s3) return 1;
	if(s2>s1 && s2>s3) return 2;
	return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		for(int i=0;i<n;i++){
			scanf("%lli %lli %lli",&tmp1,&tmp2,&tmp3);
			tmplst[0]=tmp1; tmplst[1]=tmp2; tmplst[2]=tmp3;
			sort(tmplst,tmplst+3);
//			cout << tmplst[0] << " " << tmplst[1] << " " << tmplst[2] << endl;
			pl[i]=(peo){tmp1,tmp2,tmp3,tmplst[2]-tmplst[1],tmplst[2]};
		}
		sort(pl,pl+n,cmp);
		ll c1=0, c2=0, c3=0, cnt=0;
		for(int i=0;i<n;i++){
			if(c1>=n/2) pl[i].g1 = 0;
			if(c2>=n/2) pl[i].g2 = 0;
			if(c3>=n/2) pl[i].g3 = 0;
			tmplst[1]=pl[i].g1; tmplst[2]=pl[i].g2; tmplst[3]=pl[i].g3;
			ll ret = comp(pl[i].g1, pl[i].g2, pl[i].g3);
			cnt += tmplst[ret];
			if(ret==1) c1++;
			if(ret==2) c2++;
			if(ret==3) c3++;
		}
		printf("%lli\n",cnt);
	}
	return 0;
}
