#include<bits/stdc++.h>
using namespace std;

int n,a[5100],ans,choice[5100]={-1};

bool fuhe(){
	int max=-1,all=0;
	for(int i=0;i<5100;i++){
		if(max<choice[i])
			max=choice[i];		
		if(choice[i]==-1)
			break;
		all+=choice[i];
	}
	
	if(max*2<all)
		return true;
	else
		return false;
}

void solve(){
	if(n==3){
		choice[0]=a[0],choice[1]=a[1],choice[2]=a[2];	
		if(fuhe()==true)
			ans=1;
		else
			ans=0;
		return ;
	}
		
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	solve();
	
	printf("%d",ans);
	
	return 0;
}
