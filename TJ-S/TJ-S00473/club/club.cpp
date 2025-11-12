#include <bits/stdc++.h>
using namespace std;
int t,n,e,sm[4]={},maxs=0;
long long a12[10010]={},a[10010][4];
void px(){
	int b[20000]={},max=-1;
	for (int i=1;i<=n;i++){
		b[a12[i]]++;
		if(a12[i]>max){
			max=a12[i];
		}
	}
	int hd=1;
	for (int i=max;i>=0;i--){
		while(b[i]){
			b[i]--;
			a12[hd]=i;
			hd++;
			if(hd==n+1){
				return;
			}
		}
	}
}
void mn(int s,int k){
	if(k==n+1){
		if(s>maxs){
			maxs=s;
		}
		return;
	}
	if (sm[1]==e){
		if(a[k+1][2]>=a[k+1][3]){
			sm[2]++;
			mn(s+a[k+1][2],k+1);
			sm[2]--;
		}else{
			sm[3]++;
			mn(s+a[k+1][3],k+1);
			sm[3]--;
		}
		return;
	}
	if (sm[2]==e){
		if(a[k+1][1]>=a[k+1][3]){
			sm[1]++;
			mn(s+a[k+1][1],k+1);
			sm[1]--;
		}else{
			sm[3]++;
			mn(s+a[k+1][3],k+1);
			sm[3]--;
		}
		return;
	}
	if (sm[3]==e){
		if(a[k+1][2]>=a[k+1][1]){
			sm[2]++;
			mn(s+a[k+1][2],k+1);
			sm[2]--;
		}else{
			sm[1]++;
			mn(s+a[k+1][1],k+1);
			sm[1]--;
		}
		return;
	}
	for (int i=1;i<=3;i++){
		if(sm[i]<e){
			sm[i]++;
			mn(s+a[k+1][i],k+1);
			sm[i]--;
		}
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1; x<=t; x++) {
		int f=0;
		long long s=0;
		cin>>n;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=3; j++) {
				cin>>a[i][j];
				a12[i]=a[i][1];
				if(j!=1&&a[i][j]!=0){
					f++;
				}
			}
		}
		e=n/2;
		if(!f){
			px();
			for (int i=1;i<=n/2;i++){
				s+=a12[i];
			}
			cout<<s<<endl;
			s=0;
			continue;
		}
		mn(0,0); 
		cout<<maxs<<endl;
		maxs=0;
		for(int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				a[i][j]=0;
				a12[i]=0; 
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

