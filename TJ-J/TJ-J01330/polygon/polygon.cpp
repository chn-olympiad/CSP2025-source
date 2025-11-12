#include<bits/stdc++.h>
#include<cstdio>
const int chu=998244353;
using namespace std;
int n;
int x[2500005];
char s[60005][5000];
int aa[2500005];
int bb[2500005];
int he;
int dashu;
int daan;
int q=0;
inline int jia(int a,int b,int c,int q){
	int ssum=0;
	int w=0;
	ssum+=x[a];
	s[q][w]=x[a]+'0';
	w++;
	dashu=max(dashu,x[a]);
	for(int i=b;i<=c;i++){
		ssum+=x[i];
		s[q][w]=x[i]+'0';
		w++;
		dashu=max(dashu,x[i]);
	}
	return ssum;
}
inline int jia2(int a,int b,int c,int q){
	int ssum=0;
	int w=0;
	dashu=max(dashu,x[c]);
	for(int i=a;i<=b;i++){
		ssum+=x[i];
		s[q][w]=x[i]+'0';
		w++;
		dashu=max(dashu,x[i]);
	}
	s[q][w]=x[c]+'0';
	ssum+=x[c];
	return ssum;
}
inline bool chong(int q){
	int lens;
	bool fan=0;
	int zlen=strlen(s[q]);
	for(int i=0;i<zlen;i++){
		aa[i]=s[q][i]-'0';
	}
	sort(aa+1,aa+zlen+1);
	for(int i=0;i<=q-1;i++){
		lens=strlen(s[i]);
		if(lens!=zlen){
			continue;
		}else{
			for(int j=0;j<lens;j++){
				bb[j]=s[i][j]-'0';
			}
			sort(bb+1,bb+lens+1);
			for(int j=0;j<lens;j++){
				if(aa[j]!=bb[j]){
					fan=0;
					break;
				}
				fan=1;
			}
			if(fan){
				return false;
			}
		}
	}
	return true;
}
int cha;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	sort(x+1,x+n+1);
	daan=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				dashu=-555;
				he=jia(i,j,k,q);
				cha=dashu*2;
				if(he>cha&&chong(q)){
					q++;
					daan+=1;
					daan%=chu;
				}
				if(i!=j-1||j!=k-1){
					dashu=-555;
					he=jia2(i,j,k,q);
					cha=dashu*2;
					if(he>cha&&chong(q)){
						q++;
						daan+=1;
						daan%=chu;
					}
				}
			}
		}
	}
	printf("%d",daan%chu);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
