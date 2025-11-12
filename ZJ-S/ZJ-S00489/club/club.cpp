#include<bits/stdc++.h>
using namespace std;
int st[100005][3],sat[100005][3],suoyin[100005],last[3],lin[3];;
int l,n,a,b,c;
int pin(int x,int y){
	if(st[x][sat[x][0]]+st[y][sat[y][1]]>st[x][sat[x][1]]+st[y][sat[y][0]]){
		return 0;
	}
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>l;
	for(int i=0;i<l;i++){
		cin>>n;
		memset(lin,0,sizeof(lin));
		memset(suoyin,-1,sizeof(suoyin));
		memset(last,-1,sizeof(last));
		int score=0;
		for(int j=0;j<n;j++){
			sat[j][0]=0;
			sat[j][1]=1;
			sat[j][2]=2;
			cin>>st[j][0]>>st[j][1]>>st[j][2];
			for(int p=0;p<2;p++){
				for(int x=0;x<2-p;x++){
					if(st[j][sat[j][x]]<st[j][sat[j][x+1]]){
						int hang=sat[j][x];
						sat[j][x]=sat[j][x+1];
						sat[j][x+1]=hang;
					}
				}
			}
			int flag=-1;
			if(lin[sat[j][0]]<n/2){
				if(last[sat[j][0]]==-1){
					last[sat[j][0]]=j;
				}else{
					suoyin[j]=last[sat[j][0]];
					last[sat[j][0]]=j;
				}
				score+=st[j][sat[j][0]];
				lin[sat[j][0]]+=1;
			}else{
				int b1=last[sat[j][0]],b2=last[sat[j][0]];
				int q=last[sat[j][0]],p=last[sat[j][0]];
				int com=j;
				while(p!=-1){
					if(pin(com,p)==0){
						flag=1;
						b1=q,b2=p;
						com=p;
					}
					q=p;
					p=suoyin[p];
				}
				if(flag==1){
					score=score-st[b2][sat[b2][0]]+st[b2][sat[b2][1]]+st[j][sat[j][0]];
					if(b1==b2){
						suoyin[j]=suoyin[b2];
						last[sat[j][0]]=j;
					}else{
						suoyin[j]=suoyin[b2];
						suoyin[b1]=j;
					}
					suoyin[b2]=last[sat[b2][1]];
					last[sat[b2][1]]=b2;
					lin[sat[b2][1]]+=1;
				}else{
					score+=st[j][sat[j][1]];
					suoyin[j]=last[sat[j][1]];
					last[sat[j][1]]=j;
					lin[sat[j][1]]+=1;
				}
			}
		}
		cout<<score<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
