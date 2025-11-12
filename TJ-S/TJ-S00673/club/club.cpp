#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int ad=0,bd=0,cd=0;
		int a[100100],b[100100],c[100100];
		int ansa[100100],ansb[100100],ansc[100100];
		bool fb=true,fc=true;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0){
				fb=false;
			}
			if(c[i]!=0){
				fc=false;
			}
		}
		if(fb==true&&fc==true){
			sort(a+1,a+1+n);
			cout<<a[n]+a[n-1]<<'\0';
			break;
		}
		if(n==2){
			int q=a[1]+max(b[2],c[2]);
			int w=b[1]+max(a[2],c[2]);
			int e=c[1]+max(b[2],a[2]);
			cout<<max(q,max(w,e))<<'\0';
			break;
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ansa[ad]=i;
				ad++;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
						ansb[bd]=i;
						bd++;
					}
			else if(c[i]>=a[i]&&c[i]>=b[i]){
						ansc[cd]=i;
						cd++;
					}
		}
		while(ad>n/2){
				int mina=0;
				for(int i=1;i<ad;i++){
					if(a[ansa[mina]]>a[ansa[i]]){
						mina=i;
					}
				}
				if(b[ansa[mina]]>c[ansa[mina]]){
					if(bd<n/2){
						ansb[bd]=ansa[mina];
						bd++;
					}else{
						ansc[cd]=ansa[mina];
						cd++;
					}
				}else{
					if(cd<n/2){
						ansc[cd]=ansa[mina];
						cd++;
					}else{
						ansb[bd]=ansa[mina];
						bd++;
					}
				}
				ad--;
				for(int i=mina;i<ad;i++){
					ansa[i]=ansa[i+1];
				}
			}
			while(bd>n/2){
				int minb=0;
				for(int i=1;i<bd;i++){
					if(b[ansb[minb]]>b[ansb[i]]){
						minb=i;
					}
				}
				if(a[ansb[minb]]>c[ansb[minb]]){
					if(ad<n/2){
						ansa[ad]=ansb[minb];
						ad++;
					}else{
						ansc[cd]=ansb[minb];
						cd++;
					}
				}else{
					if(cd<n/2){
						ansc[cd]=ansb[minb];
						cd++;
					}else{
						ansa[ad]=ansb[minb];
						ad++;
					}
				}
				bd--;
				for(int i=minb;i<bd;i++){
					ansb[i]=ansb[i+1];
				}
			}
			while(cd>n/2){
				int minc=0;
				for(int i=1;i<cd;i++){
					if(c[ansc[minc]]>c[ansc[i]]){
						minc=i;
					}
				}
				if(a[ansc[minc]]>b[ansc[minc]]){
					if(ad<n/2){
						ansa[ad]=ansc[minc];
						ad++;
					}else{
						ansb[bd]=ansc[minc];
						bd++;
					}
				}else{
					if(bd<n/2){
						ansb[bd]=ansc[minc];
						bd++;
					}else{
						ansa[ad]=ansc[minc];
						ad++;
					}
				}
				cd--;
				for(int i=minc;i<cd;i++){
					ansc[i]=ansc[i+1];
				}
			}
		int ansaa=0,ansbb=0,anscc=0;
		for(int i=0;i<ad;i++){
			ansaa+=a[ansa[i]];
		}
		for(int i=0;i<bd;i++){
			ansbb+=b[ansb[i]];
		}
		for(int i=0;i<cd;i++){
			anscc+=c[ansc[i]];
		}
		cout<<ansaa+ansbb+anscc<<'\0';
	}
	return 0;
}
