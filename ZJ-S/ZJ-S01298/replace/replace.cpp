#include<bits/stdc++.h>
using namespace std;
int t,i,n,q,al[1000010],qza[1000010],hza[1000010],qzb[1000010],hzb[1000010],bl[1000010],axl,qzax,qzbx,bxl,hzax,hzbx,ln,j,s;
int m,k,fl,fll,flll,fllll,flllll;
string ax,bx,x,y,a[1000010],b[1000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(n<=1000){
		for(i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		for(i=1;i<=q;i++){
			cin>>x>>y;
			m=x.length();
			fl=1;
			s=0;
			for(j=-1;j<m;j++){
				if(j>-1)
					if(x[j]-y[j])
						fl=0;
				if(fl)
					for(k=1;k<=n;k++){
						fll=1;
						if(j+a[k].length()<m){
							for(t=j+1;t<=j+a[k].length();t++)
								if(a[k][t-j-1]-x[t]){
										fll=0;
//									cout<<j<<" "<<'b'<<'\n';
									break;
								}
							if(fll){
								flll=1;
								for(t=j+1;t<=j+a[k].length();t++)
										if(b[k][t-j-1]-y[t]){
										flll=0;
//										cout<<j<<" "<<'c'<<'\n';
										break;
									}
								if(flll){
									fllll=1;
									for(t=j+a[k].length()+1;t<m;t++)
											if(x[t]-y[t]){
											fllll=0;
	//										cout<<'d';
											break;
										}
									s=s+fllll;
								}
							}
						}
					}
			}
			cout<<s<<endl;
		}
	}
	else{
		for(i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			ln=a[i].length();
			for(j=0;j<ln;j++){
				if(a[i][j]-'a'){
					al[i]=j;
					qza[i]=j-1;
					hza[i]=ln-j;
				}
				if(b[i][j]-'a'){
					bl[i]=j;
					qzb[i]=j-1;
					hzb[i]=ln-j;
				}
			}
		}
		for(i=1;i<=q;i++){
			s=0;
			cin>>ax>>bx;
			ln=ax.length();
			for(j=0;j<ln;j++){
				if(ax[j]-'a'){
					axl=j;
					qzax=j-1;
					hzax=ln-j;
				}
				if(bx[j]-'a'){
				bxl=j;
						qzbx=j-1;
					hzbx=ln-j;
				}
			}
//			cout<<axl<<" "<<bxl<<endl;
			for(t=1;t<=n;t++){
//				cout<<axl<<" "<<hzax<<' '<<qza[t]<<" "<<hza[t]<<" "<<al[t]<<" "<<bl[t]<<" "<<al[t]-bl[t]<<endl;
				if(al[t]-bl[t]==axl-bxl)
					s=s+(axl>=qza[t]&&hzax>=hza[t]);
			}
			cout<<s<<endl;
		}
	}
}
