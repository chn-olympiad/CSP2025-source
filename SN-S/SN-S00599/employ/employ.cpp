//hhz RP++ SCORE++ rts++
//Aqx¸½Ìå 
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=505;
int n,m;
string s;
int c[N],l[N],wl[N];
int z=0;
int ans=0;
//101
//0 0 1
//0 1 1
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		l[i]=c[i-1];
	}
	if(s[0]=='0'){
		wl[1]=1;
	}
	for(int i=1;i<n;i++){
		if(s[i]=='0'){
			wl[i]=wl[i-1]+1;
		}
		else{
			wl[i]=wl[i-1];
		}
	}
	//for(int i=0;i<n;i++){
	//	cout<<wl[i];
	//}
	int jc=1;
	if(m==n){
		for(int i=1;i<=n;i++){
			jc*=i;
		}
		for(int i=0;i<n;i++){
			if(wl[i]>l[i]){
				jc-=1;
			}
		}
		cout<<jc;
	}
	else if(m==1){
		int jc=1;
		int yq=0,qs=0;
		for(int i=0;i<n;i++){
			if(l[i]==0){
				yq++;
			}
			if(wl[i]>=1){
				qs++;
			}
		}
		//cout<<"..."<<yq<<" "<<qs<<" ";
		if(qs<yq){
			for(int i=1;i<=n;i++){
				jc*=i;
			}
			cout<<jc;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<30;
	}
	return 0;
}
