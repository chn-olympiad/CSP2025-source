#include <bits/stdc++.h>
using namespace std;
int n,f[100010],a[100010][5],x,y,z,T,maxx,cnt;
bool ff;
void ILoveLrh(int ct){
	if(ff)return;
	cnt++;
	if(ct>n){
		maxx=max(maxx,f[n]);
		//cout<<maxx<<endl;
		return;
	}
	if(cnt>=41000000){
		maxx=max(maxx,f[n]);
		ff=true;
		return;
	}
	if(a[ct][1]==max(a[ct][1],max(a[ct][2],a[ct][3]))){
		if(x>0){
			x--;
			f[ct]=f[ct-1]+a[ct][1];
			//cout<<1<<"x "<<x<<" ct"<<ct<<" "<<f[ct]<<endl;
			ILoveLrh(ct+1);
			if(ff)return;
			x++;
		}
		if(a[ct][2]>a[ct][3]){
			if(y>0){
				y--;
				f[ct]=f[ct-1]+a[ct][2];
				//cout<<2<<"y "<<y<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				y++;
			}
			if(z>0){
				z--;
				f[ct]=f[ct-1]+a[ct][3];
				//cout<<3<<"z "<<z<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				z++;
			}
		}else{
			if(z>0){
				z--;
				f[ct]=f[ct-1]+a[ct][3];
				//cout<<3<<"z "<<z<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				z++;
			}
			if(y>0){
				y--;
				f[ct]=f[ct-1]+a[ct][2];
				//cout<<2<<"y "<<y<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				y++;
			}
		}
	}
	else if(a[ct][2]==max(a[ct][1],max(a[ct][2],a[ct][3]))){
		if(y>0){
			y--;
			f[ct]=f[ct-1]+a[ct][2];
			//cout<<2<<"y "<<y<<" ct"<<ct<<" "<<f[ct]<<endl;
			ILoveLrh(ct+1);
			if(ff)return;
			y++;
		}
		if(a[ct][1]>a[ct][3]){
			if(x>0){
				x--;
				f[ct]=f[ct-1]+a[ct][1];
				//cout<<1<<"x "<<x<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				x++;
			}
			if(z>0){
				z--;
				f[ct]=f[ct-1]+a[ct][3];
				//cout<<3<<"z "<<z<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				z++;
			}
		}else{
			if(z>0){
				z--;
				f[ct]=f[ct-1]+a[ct][3];
				//cout<<3<<"z "<<z<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				z++;
			}
			if(x>0){
				x--;
				f[ct]=f[ct-1]+a[ct][1];
				//cout<<1<<"x "<<x<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				x++;
			}
		}
	}
	else{
		if(z>0){
			z--;
			f[ct]=f[ct-1]+a[ct][3];
			//cout<<3<<"z "<<z<<" ct"<<ct<<" "<<f[ct]<<endl;
			ILoveLrh(ct+1);
			if(ff)return;
			z++;
		}
		if(a[ct][2]>a[ct][1]){
			if(y>0){
				y--;
				f[ct]=f[ct-1]+a[ct][2];
				//cout<<2<<"y "<<y<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				y++;
			}
			if(x>0){
				x--;
				f[ct]=f[ct-1]+a[ct][1];
				//cout<<1<<"x "<<x<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				x++;
			}
		}else{
			if(x>0){
				x--;
				f[ct]=f[ct-1]+a[ct][1];
				//cout<<1<<"x "<<x<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				x++;
			}
			if(y>0){
				y--;
				f[ct]=f[ct-1]+a[ct][2];
				//cout<<2<<"y "<<y<<" ct"<<ct<<" "<<f[ct]<<endl;
				ILoveLrh(ct+1);
				if(ff)return;
				y++;
			}
		}
	}
	//cout<<ct<<"done"<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T --> 0){
		cnt=0;
		ff=false;
		maxx=-2147483647;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		memset(f,0,sizeof(f));
		x=y=z=n/2;
		ILoveLrh(1);
		cout<<maxx<<endl;
	}
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*///15:23  club done.
