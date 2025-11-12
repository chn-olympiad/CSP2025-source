#include <bits/stdc++.h>
#define ri register int
using namespace std;

inline int read(){
	int ret=0,f=1; char c;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	while(isdigit(c)) ret=(ret<<1)+(ret<<3)+(c^48),c=getchar();
	return ret*f;
}

struct department{
	int val,sub;
	const bool operator<(const department& x) const{return val<x.val;}
}temp[100010],temp2[100010];

int t,n,a[100010][3],b[4],sub1[100010],sub2[100010],ans,add1,add2,tot1,tot2,i1,i2;

void dfs(int sub,int sum){
	if(sub==n){
		ans=max(ans,sum);
		return;
	}
	for(ri i=0;i<3;i++){
		if(b[i]==n/2) continue;
		b[i]++;
		dfs(sub+1,sum+a[sub][i]);
		b[i]--;
	}
}

bool cmp(department aa,department bb){return !(aa<bb);}

int sum=0;
/*
void ts(){
	printf("i1=%d i2=%d tot1=%d tot2=%d sum=%d\n",i1,i2,tot1,tot2,sum);
}
*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	t=read();
	while(t--){
		n=read();
		for(ri i=0;i<n;i++) for(ri j=0;j<3;j++) a[i][j]=read();
		ans=0;
		
		//Circumstance A
		bool flag=1; sum=0;
		for(ri i=0;i<n;i++){
			sum+=a[i][0];
			if(!(a[i][1]==0 && a[i][2]==0)) flag=0;
		}
		if(flag){
			printf("%d\n",sum);
			continue;
		}
		
		//Circumstance B
		flag=1,sum=0;
		for(ri i=0;i<n;i++){
			sum+=a[i][0],temp[i].val=a[i][1]-a[i][0],temp[i].sub=i;
			if(a[i][2]!=0) flag=0;
		}
		if(flag){
			sort(temp,temp+n,cmp);
			for(ri i=0;i<n/2;i++) sum+=temp[i].val;
			printf("%d\n",sum);
			continue;
		}
		
		if(n<=10){
			for(ri i=0;i<3;i++) b[i]=0;
			dfs(0,0);
			printf("%d\n",ans);
		}
		else{
			memset(sub1,sizeof sub1,0);
			memset(sub2,sizeof sub2,0);
			for(ri i=0;i<n;i++) temp2[i].val=a[i][2]-a[i][0],temp2[i].sub=i;
			sort(temp,temp+n,cmp);
			sort(temp2,temp2+n,cmp);
			for(ri i=0;i<n;i++) sub1[temp[i].sub]=i,sub2[temp2[i].sub]=i;
			bitset<100010> ex;
			tot1=0,tot2=0;
			
//			printf("\nsum=%d\n",sum);
//			for(ri i=0;i<n;i++) printf("%d %d\n",temp[i].val,temp2[i].val);
			
			for(i1=0;i1<n && tot1<n/2;i1++){
				if(temp[i1].val<0) break;
				if(temp2[sub2[temp[i1].sub]].val==temp[i1].val) continue;
				if(temp2[sub2[temp[i1].sub]].val<temp[i1].val) ex[temp[i1].sub]=1,tot1++,sum+=temp[i1].val;
				if(temp2[sub2[temp[i1].sub]].val>temp[i1].val) ex[temp[i1].sub]=1,tot2++,sum+=temp2[sub2[temp[i1].sub]].val;
//				ts();
			}
			if(i1<n && tot1<n/2) for(ri i=0;i<i1;i++) if(tot1<n/2 && temp2[sub2[temp[i1].sub]].val==temp[i1].val) ex[temp[i1].sub]=1,tot1++,sum+=temp[i1].val;
			
			for(i2=0;i2<n && tot2<n/2;i2++){
				if(temp2[i2].val<0) break;
				if(ex[temp2[i2].sub]) continue;
				ex[temp2[i2].sub]=1,tot2++,sum+=temp2[i2].val;
//				ts();
			}
//			ts();
			if(tot1+tot2>=n/2) printf("%d\n",sum);
			else{
				while(tot1+tot2<n/2){
					while(tot1+tot2<n/2 && tot1<n/2) tot1++,sum+=temp[i1++].val;
					while(tot1+tot2<n/2 && tot2<n/2) tot2++,sum+=temp[i2++].val;
				}
				printf("%d\n",sum);
			}
			
			/*
			for(ri i=0;i<n/2;i++){
				if(ex[temp[i].sub]){
					if(!ex[temp2[i].sub]){
						add2=max(temp[sub1[temp2[i].sub]].val,temp2[i].val);
						if(add2<0 && tot) ex[temp2[i].sub]=1,tot--,sum+=add2;
					}
					continue;
				}
				add1=max(temp2[sub2[temp[i].sub]].val,temp[i].val);
				
				if(ex[temp2[i].sub]){
					if(add1<0 && tot) ex[temp[i].sub]=1,tot--,sum+=add1;
					continue;
				}
					
				add2=max(temp[sub1[temp2[i].sub]].val,temp2[i].val);
				
				if(add1<0 && add2<0){
					if(tot<=0) continue;
					if(add1>add2) ex[temp[i].sub]=1,tot--,sum+=add1;
					else ex[temp2[i].sub]=1,tot--,sum+=add2;
				}
				else{
					if(add1>=0) ex[temp[i].sub]=1,tot--,sum+=add1;
					if(add2>=0) ex[temp2[i].sub]=1,tot--,sum+=add2;
				}
			}
			*/
		}
	}
	
	return 0;
}/*

*/
