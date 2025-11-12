#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int arr[N][10],n,num[N][3],cnt,vis[N];

struct node{
	int val,pos;
	friend bool operator<(const node x,const node y){
		return x.val<y.val;
	}
}tmp[10],brr[N];

struct Node{
	int a,b,c,pos;
	friend bool operator<(const Node x,const Node y){
		if(x.a==y.a && x.b==y.b)return x.c>y.c;
		if(x.a==y.a)return x.b>y.b;
		return x.a>y.a;
	}
}Cnt[10];

void init(){
	memset(arr,0,sizeof arr);
	memset(num,0,sizeof num);
	memset(vis,0,sizeof vis);
	memset(tmp,0,sizeof tmp);
	memset(brr,0,sizeof brr);
	memset(Cnt,0,sizeof Cnt);
	cnt=0;
	n=0;
	
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		init();
		cin>>n;
		int ans=0;
		Cnt[1].pos=1,Cnt[2].pos=2,Cnt[3].pos=3;
		for(int i=1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
			tmp[1].val=arr[i][1];tmp[1].pos=1;
			tmp[2].val=arr[i][2];tmp[2].pos=2;
			tmp[3].val=arr[i][3];tmp[3].pos=3;
			sort(tmp+1,tmp+1+3);
			reverse(tmp+1,tmp+1+3);
			for(int j=1;j<=3;j++){
				num[i][tmp[j].pos]=j;
				if(j==1)Cnt[tmp[j].pos].a++;
				if(j==2)Cnt[tmp[j].pos].b++;
				if(j==3)Cnt[tmp[j].pos].c++;
			}
		}
		sort(Cnt+1,Cnt+1+3);
		//di1
		int fst=Cnt[1].pos,d=Cnt[2].pos,e=Cnt[3].pos;
		for(int i=1;i<=n;i++){
			if(num[i][fst]==1){
				brr[++cnt]=(node){-(arr[i][fst]-max(arr[i][d],arr[i][e])),i};
			}
		}
		sort(brr+1,brr+1+cnt);
		if(cnt<=(int)(n/2)){
			for(int i=1;i<=cnt;i++){
				vis[brr[i].pos]=24;
				ans+=arr[brr[i].pos][fst];
			}
		}else{
			for(int i=1;i<=n/2;i++){
				vis[brr[i].pos]=24;
				ans+=arr[brr[i].pos][fst];
			}
			for(int i=(n/2)+1;i<=cnt;i++){
				vis[brr[i].pos]=1;
			}
		}
		fst=Cnt[2].pos,d=Cnt[1].pos,e=Cnt[3].pos;
		cnt=0;
		//di2
		for(int i=1;i<=n;i++){
			if(num[i][fst]==1){
				brr[++cnt]=(node){-(arr[i][fst]-max(arr[i][d],arr[i][e])),i};
			}
			if(vis[i]==1 && num[i][fst]==2){
				brr[++cnt]=(node){-(arr[i][fst]-arr[i][e]),i};
			}
		}
		sort(brr+1,brr+1+cnt);
		for(int i=1;i<=min(n/2,cnt);i++){
			vis[brr[i].pos]=24;
			ans+=arr[brr[i].pos][fst];
		}
		fst=Cnt[3].pos;
		for(int i=1;i<=n;i++){
			if(vis[i]!=24){
				ans+=arr[i][fst];
			}
		}
		//cout<<Cnt[1].pos<<' ';
		cout<<ans<<endl;
	} 
	
	return 0;
}
