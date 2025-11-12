#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,num,maxNum,ans;
int ac1[N],ac2[N],ac3[N];
void ref(){
	ans=0;
	for(int i=1;i<=N;i++){
		ac1[i]=ac2[i]=ac3[i]=0;
	}
}
void px(){
	int tmp;
	while(1){
		tmp=0;
		for(int i=1;i<=num-1;i++){
			if(ac1[i]>ac1[i+1]){
				int tmp2;
				tmp2=ac1[i];
				ac1[i]=ac1[i+1];
				ac1[i+1]=tmp2;
				tmp++;
			}
		}
		if(tmp==0){
			break;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ref();
		int tot=0;
		cin>>num;
		maxNum=num/2;
		if(num==2){//case 1
			for(int i=1;i<=num;i++){
				cin>>ac1[i]>>ac2[i]>>ac3[i];
			}
			int a1,a2,a3,a4,a5,a6;
			a1=ac1[1]+ac2[2];
			a2=ac1[1]+ac3[2];
			a3=ac2[1]+ac1[2];
			a4=ac2[1]+ac3[2];
			a5=ac3[1]+ac1[2];
			a6=ac3[1]+ac2[2];
			int maxn=-1;
			maxn=max(a1,a2);
			maxn=max(maxn,a3);
			maxn=max(maxn,a4);
			maxn=max(maxn,a5);
			maxn=max(maxn,a6);
			cout<<maxn<<endl;
			continue;
		}
		for(int i=1;i<=num;i++){
			cin>>ac1[i]>>ac2[i]>>ac3[i];
			if(ac2[i]==0 and ac3[i]==0){
				tot++;
			}
		}
		if(tot==num){//case 12
			px(); 
			for(int i=num;i>maxNum;i--){
				ans+=ac1[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}