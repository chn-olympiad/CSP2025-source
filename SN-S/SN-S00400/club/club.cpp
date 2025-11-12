#include<bits/stdc++.h>
using namespace std;
//本题包含多组测试数据！！！
const int N=1e5+7; 
int t,n,peo1,peo2,peo3;
long long saf;
bool choose[N];
struct student{
	int fst,sec,trd;
	string maxs;
}club[N]; 

string maxing(student x){
	if((x.fst>x.sec&&x.fst>x.trd)||(x.fst==x.sec&&x.fst>x.trd)||(x.fst>x.sec&&x.fst==x.trd)||(x.fst==x.sec&&x.fst==x.trd)){
		return "fst";
	}
	if((x.sec>x.fst&&x.sec>x.trd)||(x.sec>x.fst&&x.sec==x.trd)){
		return "sec";
	}
	if(x.trd>x.fst&&x.trd>x.sec){
		return "trd";
	}
}

bool cmp1(student x,student y){
	return x.fst>y.fst;
}

bool cmp2(student x,student y){
	return x.sec>y.sec;
}

bool cmp3(student x,student y){
	return x.trd>y.trd;
}

void retrash(){
	for(int i=1;i<=n;i++){
		if(choose[i]) continue;
		if(club[i].maxs=="fst"){
			if(peo1<n/2){
				peo1++;
				saf+=club[i].fst;
				choose[i]=true;
			}
			else{
				if(club[i].sec>=club[i].trd){
					if(peo2<n/2){
						peo2++;
						saf+=club[i].sec;
						choose[i]=true;	
					}
					else{
						peo3++;
						saf+=club[i].trd;
						choose[i]=true;	
					}
				}
				else{
						peo3++;
						saf+=club[i].trd;
						choose[i]=true;
					}
			}
		}
		else if(club[i].maxs=="sec"){
			if(peo2<n/2){
				peo2++;
				saf+=club[i].sec;
				choose[i]=true;
			}
			else{
				if(club[i].fst>=club[i].trd){
					if(peo1<n/2){
						peo1++;
						saf+=club[i].fst;
						choose[i]=true;	
					}
					else{
						peo3++;
						saf+=club[i].trd;
						choose[i]=true;	
					}
				}
				else{
						peo3++;
						saf+=club[i].trd;
						choose[i]=true;
					}
				}
			}
		else if(club[i].maxs=="trd"){
			if(peo3<n/2){
				peo3++;
				saf+=club[i].trd;
				choose[i]=true;
			}
			else{
				if(club[i].sec>=club[i].fst){
					if(peo2<n/2){
						peo2++;
						saf+=club[i].sec;
						choose[i]=true;	
					}
					else{
						peo1++;
						saf+=club[i].fst;
						choose[i]=true;	
					}
				}
				else{
						peo1++;
						saf+=club[i].fst;
						choose[i]=true;
					}
				}
			}
		}
	}

void clearing(){
	saf=0;
	peo1=0,peo2=0,peo3=0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>club[i].fst>>club[i].sec>>club[i].trd;
			club[i].maxs=maxing(club[i]);
			choose[i]=false;
		}
		sort(club+1,club+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(peo1>=n/2) break;
			if(choose[i]) continue;
			if(club[i].maxs=="fst"){
				peo1++;
				saf+=club[i].fst;
				choose[i]=true;
			}
		}
		sort(club+1,club+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(peo2>=n/2) break;
			if(choose[i]) continue;
			if(club[i].maxs=="sec"){
				peo2++;
				saf+=club[i].sec;
				choose[i]=true;
			}
		}
		sort(club+1,club+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(peo3>=n/2) break;
			if(choose[i]) continue;
			if(club[i].maxs=="trd"){
				peo3++;
				saf+=club[i].trd;
				choose[i]=true;
			}
		}
		retrash();
		cout<<saf<<endl;
		clearing();
	}
	return 0;
}
