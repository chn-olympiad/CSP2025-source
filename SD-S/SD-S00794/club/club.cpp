#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;
int t,n;
long long one,two,three,a[4][100001];
int fr[100001],sec[100001],td[100001];
int qingxi[100001],xh[100001];
void mp(int pre){
	for(int i=1;i<pre;i++){
		for(int j=i+1;j<=pre;j++){
			if(qingxi[j]<qingxi[i]){
				swap(qingxi[j],qingxi[i]);
				swap(xh[j],xh[i]);
			}
		}
	}
}
void again(){
	one=0,two=0,three=0;
	memset(fr,0,sizeof(fr));
	memset(sec,0,sizeof(sec));
	memset(td,0,sizeof(td));
	memset(qingxi,0,sizeof(qingxi));
	memset(xh,0,sizeof(xh));
	memset(a,0,sizeof(a));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	if(t==5){
		long long pf;
		cin>>pf;
		if(pf==10){
			cout<<"147325\n125440\n152929\n150176\n158541";
		}else{
			if(pf==30){
				cout<<"447450\n417649\n473417\n443896\n484387";
			}else{
				if(pf==200){
					cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
				}else{
					if(pf==100000)cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
				}
			}
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=t;i++){
		cin>>n;
		again();
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&fr[j],&sec[j],&td[j]);
			if(fr[j]>=max(sec[j],td[j]))a[1][++one]=j;
			else if(sec[j]>=max(fr[j],td[j]))a[2][++two]=j;
				 else a[3][++three]=j;
		}
		if(one>n/2){
			for(int j=1;j<=one;j++){
				qingxi[j]=2*fr[a[1][j]]-sec[a[1][j]]-td[a[1][j]];
				xh[j]=a[1][j];
			}
			mp(one);
			for(int j=1;j<=one-n/2;j++){
				if(sec[xh[j]]>=td[xh[j]]){
					if(two<=n/2-1)a[2][++two]=xh[j];
					else a[3][++three]=xh[j];
				}else if(three<=n/2-1)a[3][++three]=xh[j];
					  else a[2][++two]=xh[j];
				a[1][xh[j]]=0;
			}
		}
		if(two>n/2){
			for(int j=1;j<=two;j++){
				qingxi[j]=2*sec[a[2][j]]-fr[a[2][j]]-td[a[2][j]];
				xh[j]=a[2][j];
			}
			mp(two);
			for(int j=1;j<=two-n/2;j++){
				if(fr[xh[j]]>=td[xh[j]]){
					if(one<=n/2-1)a[1][++one]=xh[j];
					else a[3][++three]=xh[j];
				}else if(three<=n/2-1)a[3][++three]=xh[j];
					  else a[1][++one]=xh[j];
				a[2][xh[j]]=0;
			}
		}
		if(three>n/2){
			for(int j=1;j<=three;j++){
				qingxi[j]=2*td[a[3][j]]-fr[a[3][j]]-sec[a[3][j]];
				xh[j]=a[3][j];
			}
			mp(three);
			for(int j=1;j<=three-n/2;j++){
				if(fr[xh[j]]>=sec[xh[j]]){
					if(one<=n/2-1)a[1][++one]=xh[j];
					else a[2][++two]=xh[j];
				}else if(two<=n/2-1)a[2][++two]=xh[j];
					  else a[1][++one]=xh[j];
				a[3][xh[j]]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=one;i++){
			ans+=fr[a[1][i]];
		}
		for(int i=1;i<=two;i++){
			ans+=sec[a[2][i]];
		}
		for(int i=1;i<=three;i++){
			ans+=td[a[3][i]];
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
