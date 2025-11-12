#include<bits/stdc++.h>
using namespace std;
struct club{
	int da,db,dc;
}num[100005]; 
bool cmp(club a,club b){
	return a.da>b.da;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int ans=0;
		int cnta=0,cntb=0,cntc=0;
		int cpr[4];
		scanf("%d",&n);
		int mid=n/2;
		for(int i=1;i<=n;i++){
			cin>>num[i].da>>num[i].db>>num[i].dc;
		}
		sort(num+1,num+n+1,cmp);
		for(int i=1;i<=n;i++){
			cpr[1]=num[i].da,cpr[2]=num[i].db,cpr[3]=num[i].dc;
			sort(cpr+1,cpr+4);
			if(cpr[3]==num[i].da){
				if(cnta<mid){
					ans+=cpr[3];
					cnta++;
				}else if(cntb<mid&&cpr[2]==num[i].db){
					ans+=cpr[2];
					cntb++;
				}else if(cntc<mid&&cpr[2]==num[i].dc){
					ans+=cpr[2];
					cntc++;
				}else if(cntb<mid&&cpr[1]==num[i].db){
					ans+=cpr[1];
					cntb++;
				}else if(cntc<mid&&cpr[1]==num[i].dc){
					ans+=cpr[1];
					cntc++;
				}
			}else if(cpr[3]==num[i].db){
				if(cntb<mid){
					ans+=cpr[3];
					cntb++;
				}else if(cnta<mid&&cpr[2]==num[i].da){
					ans+=cpr[2];
					cnta++;
				}else if(cntc<mid&&cpr[2]==num[i].dc){
					ans+=cpr[2];
					cntc++;
				}else if(cnta<mid&&cpr[1]==num[i].da){
					ans+=cpr[1];
					cnta++;
				}else if(cntc<mid&&cpr[1]==num[i].dc){
					ans+=cpr[1];
					cntc++;
				}
			}else if(cpr[3]==num[i].dc){
				if(cntc<mid){
					ans+=cpr[3];
					cntc++;
				}else if(cntb<mid&&cpr[2]==num[i].db){
					ans+=cpr[2];
					cntb++;
				}else if(cnta<mid&&cpr[2]==num[i].da){
					ans+=cpr[2];
					cnta++;
				}else if(cntb<mid&&cpr[1]==num[i].db){
					ans+=cpr[1];
					cntb++;
				}else if(cnta<mid&&cpr[1]==num[i].da){
					ans+=cpr[1];
					cnta++;
				}
			}else{
				continue;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
