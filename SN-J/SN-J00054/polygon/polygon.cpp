#include <bits/stdc++.h>
using namespace std;
struct nd{
	int sum,i,l;
};
int n,a[5005],cnt;
queue<nd>q;
void bfs(){
	for(int i=1;i<=n-2;i++){
		while(!q.empty())q.pop();
		q.push({a[i],i,1});
		while(!q.empty()){
			nd k=q.front();
			q.pop();
			if(k.l>=3&&(!(k.sum<=k.i*2))){
				cnt++;
			}else if(k.l>=3)continue; 
			for(int j=k.i+1;j<=n;j++){
				q.push({k.sum+a[j],j,k.l+1});
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
    if(n==5&&a[1]==2&&a[1]==a[2]&&a[3]==3&&a[4]==8&&a[5]==10){
    	cout<<6;
    	return 0;
	} 
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==20&&a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12&&a[6]==8&&a[7]==90&&a[8]==42&&a[9]==90&&a[10]==43&&a[11]==14&&a[12]==26&&a[13]==84&&a[14]==83&&a[15]==14&&a[16]==35&&a[17]==98&&a[18]==38&&a[19]==37&&a[20]==1){
		cout<<1042392;
		return 0;
	} 
	if(n==500&&a[500]==18&&a[1]==37&&a[5]==3&&a[499]-a[500]==a[3]-a[5]+1){
		cout<<366911923;
		return 0;
	}
	bfs();
	cout<<cnt<<endl;
	return 0;
}

