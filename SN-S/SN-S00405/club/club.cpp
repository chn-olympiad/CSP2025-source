#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],ans,mx[100005][2],b[3][100005],tot[3];
void read(int &x){
	x=0;
	char y=getchar();
	while(y<'0'||y>'9'){
		y=getchar();
	}
	while(y>='0'&&y<='9'){
		x=x*10+y-'0';
		y=getchar();
	}
}
void q(){
	ans=0;
	for(int i=0;i<=2;i++){
		tot[i]=0;
	}
	//cin>>n;
	read(n);
	for(int i=1;i<=n;i++){
		//cin>>a[i][0]>>a[i][1]>>a[i][2];
		read(a[i][0]);
		read(a[i][1]);
		read(a[i][2]);
		if(a[i][0]>a[i][1]){
			mx[i][0]=0;
			mx[i][1]=1;
		}
		else{
			mx[i][0]=1;
			mx[i][1]=0;
		}
		if(a[i][2]>a[i][mx[i][0]]){
			mx[i][1]=mx[i][0];
			mx[i][0]=2;
		}
		else if(a[i][2]>a[i][mx[i][1]]){
			mx[i][1]=2;
		}
		ans+=a[i][mx[i][0]];
		tot[mx[i][0]]++;
		b[mx[i][0]][tot[mx[i][0]]]=a[i][mx[i][1]]-a[i][mx[i][0]];
	}
	for(int i=0;i<=2;i++){
		sort(b[i]+1,b[i]+tot[i]+1);
		while(tot[i]>n/2){
			ans+=b[i][tot[i]];
			tot[i]--;
		}
	}
	cout<<ans<<endl;	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//cin>>t;
	read(t);
	for(int i=1;i<=t;i++){
		q();
	}
}
