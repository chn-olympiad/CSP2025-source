#include<bits/stdc++.h>
using namespace std;

int maxy(int a,int b,int c){
	int x=max(a,b);
	int y=max(b,c);
	return max(x,y);
}
int maxs(int a,int b,int c){
	int x=max(a,b);
	int y=max(b,c);
	return min(x,y);
}
int main(){
	//张可昕 SN-S00207 延安中学 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	int a1[205];
	int b1[205];
	int c1[205];
	int d1[205];
	int d2[205];
	int anss[205];
	cin>>t;
	int a,b,c,ans=0,ans2=0;
	int a2=0,b2=0,c2=0;
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			a1[i]=a;
			b1[i]=b;
			c1[i]=c;
			d1[i]=maxy(a,b,c);
			d2[i]=maxs(a,b,c);
			ans+=d1[i];
			if(maxy(a,b,c)==a) a2+=1;
			else if(maxy(a,b,c)==b) b2+=1;
			else c2+=1;
		}
		if(a2<=n/2 && b2<=n/2 && c2<=n/2){
			anss[j]=ans;
		} 
		else{
			ans2=ans-d1[1]+d2[1];
			anss[j]=ans2;
		}
	}
	for(int k=1;k<=t;k++){
		cout<<anss[k]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
