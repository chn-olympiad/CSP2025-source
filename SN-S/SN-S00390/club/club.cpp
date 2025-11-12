#include<bits/stdc++.h>
using namespace std;
int first(int a,int b,int c){
	if(a>=b && a>=c)return a;
	if(b>=a && b>=c)return b;
	return c;
}
int what(int a,int b,int c){
	if(a>=b && a>=c)return 1;
	if(b>=a && b>=c)return 2;
	return 3;
}
int second(int a,int b){
	if(a>b)return a;
	return b;
}
int change(int a,int b,int c)
{
	int d=first(a,b,c),e=what(a,b,c);
	if(e==1) return d-second(b,c);
	if(e==2)return d-second(a,c);
	return d-second(a,b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0,n=0,add=0,i=0,j=0,p=0,q=0,max=0,min=0;
	cin>>t;
	for(p=0;p<t;p++){//每组 
		cin>>n; 
		max=n/2;
		int a[n],b[n],st[n];
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		memset(st,-1,sizeof(st));
		for(j=0;j<n;j++){//组内算ab 
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			a[j]=first(a1,a2,a3);
			st[j]=what(a1,a2,a3);
			b[j]=change(a1,a2,a3); 	
		}

		int th[max];//替换变量 
		memset(th,-1,sizeof(th));//替换 
		bool w=true;
		j=0;
		while(j<n){
			int xt=0;//替换的个数 
			while(q<n){//查找 
				if(st[j]==st[q]){
					xt++;
					th[q]=b[q];
				} 
				if(xt>max) {
					w=false;
				}
				q++;
			}
			q=0; 
			if(!w){//替换 	
				for(q=0;q<(xt-max);q++){ 
					min=0; 
					for(int r=0;r<n;r++)if((th[min]>th[r])&&th[r]!=-1){//找最小 
						min=r;
					}
					a[min]=a[min]-b[min];
					th[min]=-1;
				}
				break;	
			}//替换结束 
			memset(th,-1,sizeof(th));	
			j++;
		}//结束 
		for(i=0;i<n;i++)add+=a[i]; 
		cout<<add<<endl;
		add=0;
	}
	return 0;
}
