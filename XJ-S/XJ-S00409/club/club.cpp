#include<bits/stdc++.h>
using namespace std;
int t;						//循环次数 
int a[100000+1][4];
int text[4];   			//3个部门人数 
int c[100000+1];		//每个人选择的部门编号 
int club(int n){		//输入 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			a[i][j] = 0;
			cin >> a[i][j];
		}
	}
} 
int choose(int n){		//选择部门 
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
			c[i]=1;
		}
		else if(a[i][1]<a[i][2] && a[i][2]>a[i][3]){
			c[i]=2;
		}
		else if(a[i][1]<a[i][3] && a[i][3]>a[i][2]){
			c[i]=3;
		}
	}
}
void jiance(int n);
void del(int n,int which){			//which部门人数超 
	int maxn = n/2;
	int mina=0,maxa=0;						//mina确定which部门兴趣最低的人编号 
	while(c[mina]!=which){
		mina++;
	}
	maxa=mina;
	for(int i=1;i<=n;i++){
		if((c[i]==which)&&(a[mina][which]>a[i][which])){
			mina = i;
		}
		if((c[i]==which)&&(a[maxa][which]<a[i][which])){
			maxa = i;
		}
	}
	if(which == 1){
		if(max(a[mina][2],a[mina][3])<max(a[maxa][2],a[maxa][3])){
			if(a[maxa][2]>a[maxa][3]){
				text[2]++;
				c[maxa]=2;
				return;
			}
			else{
				text[3]++;
				c[maxa]=3;
				return;
			}
		}
		else{
			if(a[mina][2]>a[mina][3]){
				text[2]++;
				c[mina]=2;
				return;
			}
			else{
				text[3]++;
				c[mina]=3;
				return;
			}
		}
	}
	if(which == 2){
		if(max(a[mina][1],a[mina][3])<max(a[maxa][1],a[maxa][3])){
			if(a[maxa][1]>a[maxa][3]){
				text[1]++;
				c[maxa]=1;
				return;
			}
			else{
				text[3]++;
				c[maxa]=3;
				return;
			}
		}
		else{
			if(a[mina][1]>a[mina][3]){
				text[1]++;
				c[mina]=1;
				return;
			}
			else{
				text[3]++;
				c[mina]=3;
				return;
			}
		}
	}
	if(which == 3){
		if(max(a[mina][1],a[mina][2])<max(a[maxa][1],a[maxa][2])){
			if(a[maxa][1]>a[maxa][2]){
				text[1]++;
				c[maxa]=1;
				return;
			}
			else{
				text[2]++;
				c[maxa]=2;
				return;
			}
		}
		else{
			if(a[mina][1]>a[mina][2]){
				text[1]++;
				c[mina]=1;
				return;
			}
			else{
				text[2]++;
				c[mina]=2;
				return;
			}
		}
	}
}
void jiance(int n){  		//检测每部门是否超人 
	int maxn = n/2;
	while(text[1]>maxn){
		del(n,1);
		text[1]--;
	}
	while(text[2]>maxn){
		del(n,2);
		text[2]--;
	}
	while(text[3]>maxn){
		del(n,3);
		text[3]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;             //循环次数 
	cin >> t;
	while(t>0){
		int n=0,sum=0;
		text[1]=0,text[2]=0,text[3]=0;
		int b[n+1];
		cin >> n;
		club(n);
		choose(n);
		for(int i=1;i<=n;i++){
			if(c[i]==1)		text[1]++;
			else if(c[i]==2)	text[2]++;
			else if(c[i]==3)	text[3]++;
		}
		jiance(n);
		jiance(n);
		for(int i=1;i<=n;i++){
			sum+=a[i][c[i]];
		}
		cout << sum << endl;
		t--;		//跳出循环 
	}
	return 0;
}

