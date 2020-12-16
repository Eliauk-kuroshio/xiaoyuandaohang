#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define inf 99999999
using namespace std;
void kaishidaohang();
void daohanglan();
int map[110][110],book[110],dis[110];
struct A		//定义结构体存储景点信息 
{
	char name[100];
	char jieshao[800];
}q[100];
void cuntu()		//存储景点信息、同时存图，各边信息 
{
	int i,j;
	strcpy(q[1].name,"学校大门");strcpy(q[1].jieshao,"设有地铁站");
	strcpy(q[2].name,"体育馆");strcpy(q[2].jieshao,"设有室内乒乓球、室内羽毛球、室内篮球场地");
	strcpy(q[3].name,"行政楼");strcpy(q[3].jieshao,"学校领导办公场所"); 
	strcpy(q[4].name,"纪念会馆");strcpy(q[4].jieshao,"正门为创办人纪念馆、学校大型活动举办场所");
	strcpy(q[5].name,"图书馆");strcpy(q[5].jieshao,"学校图书馆"); 
	strcpy(q[6].name,"一食堂");strcpy(q[6].jieshao,"一、二楼为餐厅，三楼为报告厅");
	strcpy(q[7].name,"一号楼、综合楼");strcpy(q[7].jieshao,"教学楼");
	strcpy(q[8].name,"新主楼");strcpy(q[8].jieshao,"教学楼");
	strcpy(q[9].name,"理学院");strcpy(q[9].jieshao,"教学楼");
	strcpy(q[10].name,"资讯大楼");strcpy(q[10].jieshao,"教学楼");
	strcpy(q[11].name,"道荣楼");strcpy(q[11].jieshao,"教学楼");
	strcpy(q[12].name,"时金楼");strcpy(q[12].jieshao,"教学楼");
	strcpy(q[13].name,"七公寓");strcpy(q[13].jieshao,"学生宿舍楼");
	strcpy(q[14].name,"生活馆");strcpy(q[14].jieshao,"一楼为商店学生买一些生活用品、二楼为餐厅");
	strcpy(q[15].name,"体育场");strcpy(q[15].jieshao,"举办运动会、锻炼身体的好去处");
	strcpy(q[16].name,"夜市");strcpy(q[16].jieshao,"外有小吃");
	strcpy(q[17].name,"艺文广场");strcpy(q[17].jieshao,"学生活动场所");
	strcpy(q[18].name,"博新楼");strcpy(q[18].jieshao,"一楼二楼为餐厅、三楼为学生社团活动室");
	strcpy(q[19].name,"一号餐厅");strcpy(q[19].jieshao,"二楼大盘鸡面不错哦！");
	strcpy(q[20].name,"二号餐厅");strcpy(q[20].jieshao,"一楼麻辣烫可以哦！");
	strcpy(q[21].name,"三公寓");strcpy(q[21].jieshao,"学生宿舍楼");
	strcpy(q[22].name,"台球室");strcpy(q[22].jieshao,"学生娱乐场所");
	strcpy(q[23].name,"跑道");strcpy(q[23].jieshao,"一圈1100米！");
	strcpy(q[24].name,"南区学生宿舍");strcpy(q[24].jieshao,"学生宿舍楼");
	strcpy(q[25].name,"冰场");strcpy(q[25].jieshao,"滑冰场地");
	strcpy(q[26].name,"建工实训大楼");strcpy(q[26].jieshao,"教学楼");
	for(i=1;i<=28;i++)
		for(j=1;j<=28;j++)
		{
			if(i==j)
				map[i][j]=0;
			else
				map[i][j]=inf;
		}
	map[1][2]=40;map[1][16]=140;map[1][3]=80;
	map[2][3]=50;map[2][1]=40;
	map[3][4]=50;map[3][5]=90;map[3][17]=50;map[3][1]=80;map[3][2]=50;
	map[4][6]=70;map[4][15]=80;map[4][3]=50;
	map[5][3]=90;map[5][20]=140;map[5][17]=130;map[5][7]=90;
	map[6][4]=70;map[6][8]=40;map[6][7]=30;
	map[7][6]=30;map[7][10]=80;map[7][5]=90;
	map[8][6]=40;map[8][9]=30;
	map[9][8]=30;map[9][10]=60;map[9][15]=90;
	map[10][9]=60;map[10][7]=80;map[10][11]=60;
	map[11][10]=60;map[11][12]=60;
	map[12][11]=60;map[12][13]=100;
	map[13][12]=100;map[13][14]=70;
	map[14][13]=70;map[14][16]=100;map[14][15]=80;
	map[15][9]=90;map[15][4]=80;map[15][14]=80;map[15][16]=90;
	map[16][1]=140;map[16][15]=90;map[16][14]=100;
	map[17][3]=50;map[17][5]=130;map[17][18]=40;
	map[18][17]=40;map[18][19]=50;map[18][20]=40;
	map[19][18]=50;map[19][24]=150;
	map[20][18]=40;map[20][21]=30;map[20][5]=140;
	map[21][20]=30;
	map[22][23]=50;map[22][25]=70;
	map[23][22]=50;map[23][24]=130;
	map[24][19]=150;map[24][23]=130;map[24][25]=100;
	map[25][22]=70;map[25][24]=100;map[25][26]=200;
	map[26][25]=200;
//	for(i=1;i<=26;i++)
//	{
//		for(j=1;j<=26;j++)
//			printf("%d ",map[i][j]);
//		printf("\n"); 
//	}
	for(i=1;i<=26;i++)
		for(j=1;j<=26;j++)
			map[j][i]=map[i][j];
//	printf("\n\n\n\n");
//	for(i=1;i<=26;i++)
//	{
//		for(j=1;j<=26;j++)
//			printf("%d ",map[i][j]);
//		printf("\n"); 
//	}
}
 
void liebiao()			//景点列表 
{
	system("cls");			//清屏 
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *"<<endl;
	cout<<"\t\t\t\t\t * *                     *景点列表*                     * *"<<endl;
	cout<<"\t\t\t\t\t * ****************************************************** *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <1>学校大门  <2>体育馆  <3>行政楼   <4>纪念会馆   * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <5>图书馆    <6>一食堂    <7>一号楼、综合楼       * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <8>新主楼   <9>理学院   <10>资讯大楼  <11>道荣楼  * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <12>时金楼     <13>七公寓     <14>生活馆          * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <15>体育场     <16>夜市        <17>艺文广场       * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <18>博新楼     <19>一号餐厅    <20>二号餐厅       * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <21>三公寓     <22>台球室       <23>跑道          * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <24>南区学生宿舍   <25>冰场   <26>建工实训大楼    * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * ****************************************************** *"<<endl;
	cout<<"\t\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *"<<endl;
	cout<<"\n\n\n";
}
 
//查询方式 
int chaxunfangshi(int x)
{
	int i;
	system("cls");			//清屏 
	cout<<"\n";
	cout<<"\t\t\t\t\t                    *请输入查询方式*"<<"\n\n";
	cout<<"\t\t\t\t\t                  1、输入景点编号查询"<<"\n\n";
	cout<<"\t\t\t\t\t                  2、输入景点名称查询"<<"\n\n";
	cout<<"\t\t\t\t\t                  0、返回上一界面"<<"\n\n\n\n\n\n\n";
	cin>>i;
	return i;
} 
 
//查询景点编号 
int bianhao(char s[])
{
	int f=0,i;
	for(i=1;i<=26;i++)
	{
		if(strcmp(q[i].name,s)==0)
			return i;
	}
	return -1;
}
 
void Dijkstra(int v0,int s)		//迪杰斯特拉求最短路径，并输出路线 
{
	int min,i,j,u,v;
	int p[110],l[110];
	memset(p,-1,sizeof(p));
	memset(l,0,sizeof(l));
	memset(book,0,sizeof(book));
	for(i=1;i<=26;i++)
	{
		dis[i]=map[v0][i];
		if(dis[i]<inf)			//v0能直接到达，即上一站点为v0 
			p[i]=v0;
	}
		
	book[v0]=1;
	
	for(i=1;i<26;i++)
	{
		min=inf;
		for(j=1;j<=26;j++)			//每次找出距离v0最近点 
		{
			if(book[j]==0&&dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		}
		book[u]=1;			//标记该点 
		for(v=1;v<=26;v++)
		{
			if(book[v]==0&&dis[v]>dis[u]+map[u][v])			//通过最近点更新其他边 
			{
				p[v]=u;					//存储更新的边，即为路线 
				dis[v]=dis[u]+map[u][v];
			}
		}
	}
	v=s;
	i=1;
	while(p[v]!=v0)			//将路线存入栈中，正序输出 
	{
		
		l[i++]=p[v];
		v=p[v];
	}
	cout<<"\n";
	u=i-1;
	cout<<"路线为："<<endl;
	cout<<q[v0].name<<"--->";
	for(i=u;i>=1;i--)
		cout<<q[l[i]].name<<"--->"; 
	cout<<q[s].name<<endl;
	cout<<"最短路径长度为："<< dis[s]<<"米\n";
}
 
//导航界面 
void kaishidaohang()
{
	int x,m,n,u,v,i,j;
	char c[100];
	system("cls");			//清屏 
	cout<<"\n\n\n";
	cout<<"\t\t\t\t ■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout<<"\t\t\t\t ■                                          ■\n";
	cout<<"\t\t\t\t ■      欢 迎 使 用 校 园 导 航 系 统       ■\n";
	cout<<"\t\t\t\t ■                                          ■\n";
	cout<<"\t\t\t\t ■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout<<"\n\n\n";
	cout<<"\t\t\t    1、遍历所有景点；\t\t\t2、查询任意景点信息；\n\n\n";
	cout<<"\t\t\t    3、查询任意两景点间的最短路径；     4、返回至主界面；\n";
	cout<<"\n\n\n";
	
	while(1)//实现输入错误可重新输入 
	{
		cin>>x;
		if(x==1)
		{
			v=chaxunfangshi(x);
			while(1)
			{
				if(v==1)
				{
					liebiao();
					cout<<"请输入当前所在景点编号：\n"; 
					cin>>n;
					while(1)
					{
						if(n>=1&&n<=26)
						{
							for(i=1;i<=26;i++)
							{
								if(i!=n)
									Dijkstra(n,i);
							}
							cout<<"\n\n按回车键返回至导航系统界面\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n该景点不存在！请重新输入景点编号：\n";
							cin>>n;
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					cout<<"请输入当前所在景点名称：\n";
					cin>>c;
					n=bianhao(c);
					while(1)
					{
						if(n>=1&&n<=26)
						{
							for(i=1;i<=26;i++)
							{
								if(i!=n)
									Dijkstra(n,i);
							}
							cout<<"\n\n按回车键返回至导航系统界面\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n该景点不存在！请重新输入景点名称：\n";
							cin>>c;
							n=bianhao(c);
						}
					}
					break;
				}
				else if(v==0)
				{
					kaishidaohang();
					break;
				}
				else
				{
					cout<<"\n\n输入错误请重新输入！\n\n";
					cin>>v;
				}
			}
			break;
		}
		else if(x==2)
		{
			v=chaxunfangshi(x);
			while(1)
			{
				if(v==1)
				{
					liebiao();
					cout<<"请输入景点编号：\n"; 
					cin>>n;
					while(1)
					{
						if(n>=1&&n<=26)
						{
							cout<<"\n\n"<<q[n].name<<"\n\n"<<q[n].jieshao<<"\n\n";
							cout<<"按回车键返回至导航系统界面\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n该景点不存在！请重新输入景点编号：\n";
							cin>>n;
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					cout<<"请输入景点名称：\n";
					cin>>c;
					n=bianhao(c);
					while(1)
					{
						if(n>=1&&n<=26)
						{
							cout<<"\n\n"<<q[n].name<<"\n\n"<<q[n].jieshao<<"\n\n";
							cout<<"按回车键返回至导航系统界面\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n该景点不存在！请重新输入景点名称：\n";
							cin>>c;
							n=bianhao(c);
						}
					}
					break;
				}
				else if(v==0)
				{
					kaishidaohang();
					break;
				}
				else
				{
					cout<<"\n\n输入错误请重新输入！\n\n";
					cin>>v;
				}
			}
			break;
		}
		else if(x==3)
		{
			v=chaxunfangshi(x);
			while(1)
			{
				if(v==1)
				{
					liebiao();
					cout<<"请输入起点景点编号：\n";
					cin>>n;
					cout<<"\n请输入终点景点编号：\n";
					cin>>m;
					while(1)
					{
						if(n>=1&&n<=26&&m>=1&&m<=26&&n!=m)
						{
							Dijkstra(n,m);
							cout<<"\n\n按回车键返回至导航系统界面\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n输入不合法！请重新输入！\n\n";
							cout<<"请输入起点景点编号：\n";
							cin>>n;
							cout<<"\n请输入终点景点编号：\n";
							cin>>m;
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					cout<<"请输入起点景点名称：\n";
					cin>>c;
					n=bianhao(c);
					cout<<"\n请输入终点景点名称：\n";
					cin>>c;
					m=bianhao(c);
					while(1)
					{
						if(n>=1&&n<=26&&m>=1&&m<=26&&n!=m)
						{
							Dijkstra(n,m);
							cout<<"\n\n按回车键返回至导航系统界面\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n输入不合法！请重新输入！\n\n";
							cout<<"请输入起点景点名称：\n";
							cin>>c;
							n=bianhao(c);
							cout<<"\n请输入终点景点名称：\n";
							cin>>c;
							m=bianhao(c);
						}
					}
					break;
				}
				else if(v==0)
				{
					kaishidaohang();
					break;
				}
				else
				{
					cout<<"\n\n输入错误请重新输入！\n\n";
					cin>>v;
				}
			}
			break;
		}
		else if(x==4)
		{
			daohanglan();
			break;
		}
		else
		{
			cout<<"\n\n输入错误！请重新输入！\n";
		}
	}
	
}
//导航栏主界面 
void daohanglan()
{
	system("cls");		//清屏 
	int m;
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t    ******************************************************\n";
	cout<<"\t\t\t\t\t    *----------------------主界面------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------1、进入导航系统---------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------2、导航简介-------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------3、退出程序-------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------4、制作人---------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    ******************************************************\n";
	cin>>m;
	while(1)
	{
		if(m==1)
		{
			kaishidaohang();
			break;
		}
		else if(m==2)
		{
			system("cls");
			cout<<"\n\n\n\n\n";
			cout<<"\t\t\t\t\t    ****************************************************\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    *     此导航将校园设计为平面图，将学校各代表       *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    * 构成一个抽象的无向带权图，顶点为景点景点边的权值 *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    * 代表了景点间路径的长度。设计出能够帮助人们       *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    * 快速找到从一个景点到达另一景点的最短路径         *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    * 及路线；以及能够显示任意景点信息的程序。         *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    ****************************************************\n";
			cout<<"\n\n\n\n\n";
			cout<<"按回车键返回主界面\n";
			getchar();getchar();
			daohanglan();
			break;
		}
		else if(m==3)
		{
			system("cls");
			cout<<"\n\n\n\n\n";
			cout<<"\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴\n";
			cout<<"\t\t\t\t\t∴∵                      ∴∵\n";
			cout<<"\t\t\t\t\t∴∵      欢 迎 使 用     ∴∵\n";
			cout<<"\t\t\t\t\t∴∵                      ∴∵\n";
			cout<<"\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴\n";
			cout<<"\n\n\n"; 
			break;
		}
		else if(m==4)
		{
			system("cls");		//清屏 
			cout<<"\n\n\n\n\n";
			cout<<"\t\t\t\t\t    ****************************************************\n";
			cout<<"\t\t\t\t\t    *                     制作人                       *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    *                19级软件工程4班                   *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    *                     王希宁                       *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    ****************************************************\n";
			cout<<"\n\n\n\n\n";
			cout<<"按回车键返回主界面\n";
			getchar();getchar();
			daohanglan();
			break;
		}
		else
		{
			cout<<"\n\n\n\t\t输入错误请重新输入！\n\n\n\n";
			cin>>m; 
		}
	}
	
}
//欢迎进入 
void zhujiemian()
{
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t    ******************************************************\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *---------------------Welcome!-----------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *-------------------校园导航系统---------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *-------------------按回车键继续---------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    ******************************************************\n";
	getchar();
		
	daohanglan();
}
int main(void)
{
	system("mode con cols=150 lines=200");		//改变运行窗口大小 
	cuntu();
	//getchar();getchar();
	zhujiemian();
	return 0;
}
