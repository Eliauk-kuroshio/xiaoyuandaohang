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
struct A		//����ṹ��洢������Ϣ 
{
	char name[100];
	char jieshao[800];
}q[100];
void cuntu()		//�洢������Ϣ��ͬʱ��ͼ��������Ϣ 
{
	int i,j;
	strcpy(q[1].name,"ѧУ����");strcpy(q[1].jieshao,"���е���վ");
	strcpy(q[2].name,"������");strcpy(q[2].jieshao,"��������ƹ����������ë���������򳡵�");
	strcpy(q[3].name,"����¥");strcpy(q[3].jieshao,"ѧУ�쵼�칫����"); 
	strcpy(q[4].name,"������");strcpy(q[4].jieshao,"����Ϊ�����˼���ݡ�ѧУ���ͻ�ٰ쳡��");
	strcpy(q[5].name,"ͼ���");strcpy(q[5].jieshao,"ѧУͼ���"); 
	strcpy(q[6].name,"һʳ��");strcpy(q[6].jieshao,"һ����¥Ϊ��������¥Ϊ������");
	strcpy(q[7].name,"һ��¥���ۺ�¥");strcpy(q[7].jieshao,"��ѧ¥");
	strcpy(q[8].name,"����¥");strcpy(q[8].jieshao,"��ѧ¥");
	strcpy(q[9].name,"��ѧԺ");strcpy(q[9].jieshao,"��ѧ¥");
	strcpy(q[10].name,"��Ѷ��¥");strcpy(q[10].jieshao,"��ѧ¥");
	strcpy(q[11].name,"����¥");strcpy(q[11].jieshao,"��ѧ¥");
	strcpy(q[12].name,"ʱ��¥");strcpy(q[12].jieshao,"��ѧ¥");
	strcpy(q[13].name,"�߹�Ԣ");strcpy(q[13].jieshao,"ѧ������¥");
	strcpy(q[14].name,"�����");strcpy(q[14].jieshao,"һ¥Ϊ�̵�ѧ����һЩ������Ʒ����¥Ϊ����");
	strcpy(q[15].name,"������");strcpy(q[15].jieshao,"�ٰ��˶��ᡢ��������ĺ�ȥ��");
	strcpy(q[16].name,"ҹ��");strcpy(q[16].jieshao,"����С��");
	strcpy(q[17].name,"���Ĺ㳡");strcpy(q[17].jieshao,"ѧ�������");
	strcpy(q[18].name,"����¥");strcpy(q[18].jieshao,"һ¥��¥Ϊ��������¥Ϊѧ�����Ż��");
	strcpy(q[19].name,"һ�Ų���");strcpy(q[19].jieshao,"��¥���̼��治��Ŷ��");
	strcpy(q[20].name,"���Ų���");strcpy(q[20].jieshao,"һ¥�����̿���Ŷ��");
	strcpy(q[21].name,"����Ԣ");strcpy(q[21].jieshao,"ѧ������¥");
	strcpy(q[22].name,"̨����");strcpy(q[22].jieshao,"ѧ�����ֳ���");
	strcpy(q[23].name,"�ܵ�");strcpy(q[23].jieshao,"һȦ1100�ף�");
	strcpy(q[24].name,"����ѧ������");strcpy(q[24].jieshao,"ѧ������¥");
	strcpy(q[25].name,"����");strcpy(q[25].jieshao,"��������");
	strcpy(q[26].name,"����ʵѵ��¥");strcpy(q[26].jieshao,"��ѧ¥");
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
 
void liebiao()			//�����б� 
{
	system("cls");			//���� 
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *"<<endl;
	cout<<"\t\t\t\t\t * *                     *�����б�*                     * *"<<endl;
	cout<<"\t\t\t\t\t * ****************************************************** *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <1>ѧУ����  <2>������  <3>����¥   <4>������   * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <5>ͼ���    <6>һʳ��    <7>һ��¥���ۺ�¥       * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <8>����¥   <9>��ѧԺ   <10>��Ѷ��¥  <11>����¥  * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <12>ʱ��¥     <13>�߹�Ԣ     <14>�����          * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <15>������     <16>ҹ��        <17>���Ĺ㳡       * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <18>����¥     <19>һ�Ų���    <20>���Ų���       * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <21>����Ԣ     <22>̨����       <23>�ܵ�          * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * *  <24>����ѧ������   <25>����   <26>����ʵѵ��¥    * *"<<endl;
	cout<<"\t\t\t\t\t * *                                                    * *"<<endl;
	cout<<"\t\t\t\t\t * ****************************************************** *"<<endl;
	cout<<"\t\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *"<<endl;
	cout<<"\n\n\n";
}
 
//��ѯ��ʽ 
int chaxunfangshi(int x)
{
	int i;
	system("cls");			//���� 
	cout<<"\n";
	cout<<"\t\t\t\t\t                    *�������ѯ��ʽ*"<<"\n\n";
	cout<<"\t\t\t\t\t                  1�����뾰���Ų�ѯ"<<"\n\n";
	cout<<"\t\t\t\t\t                  2�����뾰�����Ʋ�ѯ"<<"\n\n";
	cout<<"\t\t\t\t\t                  0��������һ����"<<"\n\n\n\n\n\n\n";
	cin>>i;
	return i;
} 
 
//��ѯ������ 
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
 
void Dijkstra(int v0,int s)		//�Ͻ�˹���������·���������·�� 
{
	int min,i,j,u,v;
	int p[110],l[110];
	memset(p,-1,sizeof(p));
	memset(l,0,sizeof(l));
	memset(book,0,sizeof(book));
	for(i=1;i<=26;i++)
	{
		dis[i]=map[v0][i];
		if(dis[i]<inf)			//v0��ֱ�ӵ������һվ��Ϊv0 
			p[i]=v0;
	}
		
	book[v0]=1;
	
	for(i=1;i<26;i++)
	{
		min=inf;
		for(j=1;j<=26;j++)			//ÿ���ҳ�����v0����� 
		{
			if(book[j]==0&&dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		}
		book[u]=1;			//��Ǹõ� 
		for(v=1;v<=26;v++)
		{
			if(book[v]==0&&dis[v]>dis[u]+map[u][v])			//ͨ���������������� 
			{
				p[v]=u;					//�洢���µıߣ���Ϊ·�� 
				dis[v]=dis[u]+map[u][v];
			}
		}
	}
	v=s;
	i=1;
	while(p[v]!=v0)			//��·�ߴ���ջ�У�������� 
	{
		
		l[i++]=p[v];
		v=p[v];
	}
	cout<<"\n";
	u=i-1;
	cout<<"·��Ϊ��"<<endl;
	cout<<q[v0].name<<"--->";
	for(i=u;i>=1;i--)
		cout<<q[l[i]].name<<"--->"; 
	cout<<q[s].name<<endl;
	cout<<"���·������Ϊ��"<< dis[s]<<"��\n";
}
 
//�������� 
void kaishidaohang()
{
	int x,m,n,u,v,i,j;
	char c[100];
	system("cls");			//���� 
	cout<<"\n\n\n";
	cout<<"\t\t\t\t ����������������������������������������������\n";
	cout<<"\t\t\t\t ��                                          ��\n";
	cout<<"\t\t\t\t ��      �� ӭ ʹ �� У ԰ �� �� ϵ ͳ       ��\n";
	cout<<"\t\t\t\t ��                                          ��\n";
	cout<<"\t\t\t\t ����������������������������������������������\n";
	cout<<"\n\n\n";
	cout<<"\t\t\t    1���������о��㣻\t\t\t2����ѯ���⾰����Ϣ��\n\n\n";
	cout<<"\t\t\t    3����ѯ���������������·����     4�������������棻\n";
	cout<<"\n\n\n";
	
	while(1)//ʵ������������������ 
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
					cout<<"�����뵱ǰ���ھ����ţ�\n"; 
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
							cout<<"\n\n���س�������������ϵͳ����\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n�þ��㲻���ڣ����������뾰���ţ�\n";
							cin>>n;
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					cout<<"�����뵱ǰ���ھ������ƣ�\n";
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
							cout<<"\n\n���س�������������ϵͳ����\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n�þ��㲻���ڣ����������뾰�����ƣ�\n";
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
					cout<<"\n\n����������������룡\n\n";
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
					cout<<"�����뾰���ţ�\n"; 
					cin>>n;
					while(1)
					{
						if(n>=1&&n<=26)
						{
							cout<<"\n\n"<<q[n].name<<"\n\n"<<q[n].jieshao<<"\n\n";
							cout<<"���س�������������ϵͳ����\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n�þ��㲻���ڣ����������뾰���ţ�\n";
							cin>>n;
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					cout<<"�����뾰�����ƣ�\n";
					cin>>c;
					n=bianhao(c);
					while(1)
					{
						if(n>=1&&n<=26)
						{
							cout<<"\n\n"<<q[n].name<<"\n\n"<<q[n].jieshao<<"\n\n";
							cout<<"���س�������������ϵͳ����\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n�þ��㲻���ڣ����������뾰�����ƣ�\n";
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
					cout<<"\n\n����������������룡\n\n";
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
					cout<<"��������㾰���ţ�\n";
					cin>>n;
					cout<<"\n�������յ㾰���ţ�\n";
					cin>>m;
					while(1)
					{
						if(n>=1&&n<=26&&m>=1&&m<=26&&n!=m)
						{
							Dijkstra(n,m);
							cout<<"\n\n���س�������������ϵͳ����\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n���벻�Ϸ������������룡\n\n";
							cout<<"��������㾰���ţ�\n";
							cin>>n;
							cout<<"\n�������յ㾰���ţ�\n";
							cin>>m;
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					cout<<"��������㾰�����ƣ�\n";
					cin>>c;
					n=bianhao(c);
					cout<<"\n�������յ㾰�����ƣ�\n";
					cin>>c;
					m=bianhao(c);
					while(1)
					{
						if(n>=1&&n<=26&&m>=1&&m<=26&&n!=m)
						{
							Dijkstra(n,m);
							cout<<"\n\n���س�������������ϵͳ����\n\n";
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							cout<<"\n���벻�Ϸ������������룡\n\n";
							cout<<"��������㾰�����ƣ�\n";
							cin>>c;
							n=bianhao(c);
							cout<<"\n�������յ㾰�����ƣ�\n";
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
					cout<<"\n\n����������������룡\n\n";
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
			cout<<"\n\n����������������룡\n";
		}
	}
	
}
//������������ 
void daohanglan()
{
	system("cls");		//���� 
	int m;
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t    ******************************************************\n";
	cout<<"\t\t\t\t\t    *----------------------������------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------1�����뵼��ϵͳ---------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------2���������-------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------3���˳�����-------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------4��������---------------------------*\n";
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
			cout<<"\t\t\t\t\t    *     �˵�����У԰���Ϊƽ��ͼ����ѧУ������       *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    * ����һ������������Ȩͼ������Ϊ���㾰��ߵ�Ȩֵ *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    * �����˾����·���ĳ��ȡ���Ƴ��ܹ���������       *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    * �����ҵ���һ�����㵽����һ��������·��         *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    * ��·�ߣ��Լ��ܹ���ʾ���⾰����Ϣ�ĳ���         *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    ****************************************************\n";
			cout<<"\n\n\n\n\n";
			cout<<"���س�������������\n";
			getchar();getchar();
			daohanglan();
			break;
		}
		else if(m==3)
		{
			system("cls");
			cout<<"\n\n\n\n\n";
			cout<<"\t\t\t\t\t��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�\n";
			cout<<"\t\t\t\t\t���                      ���\n";
			cout<<"\t\t\t\t\t���      �� ӭ ʹ ��     ���\n";
			cout<<"\t\t\t\t\t���                      ���\n";
			cout<<"\t\t\t\t\t��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�\n";
			cout<<"\n\n\n"; 
			break;
		}
		else if(m==4)
		{
			system("cls");		//���� 
			cout<<"\n\n\n\n\n";
			cout<<"\t\t\t\t\t    ****************************************************\n";
			cout<<"\t\t\t\t\t    *                     ������                       *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    *                19���������4��                   *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    *                     ��ϣ��                       *\n";
			cout<<"\t\t\t\t\t    *                                                  *\n";
			cout<<"\t\t\t\t\t    ****************************************************\n";
			cout<<"\n\n\n\n\n";
			cout<<"���س�������������\n";
			getchar();getchar();
			daohanglan();
			break;
		}
		else
		{
			cout<<"\n\n\n\t\t����������������룡\n\n\n\n";
			cin>>m; 
		}
	}
	
}
//��ӭ���� 
void zhujiemian()
{
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t    ******************************************************\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *---------------------Welcome!-----------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *-------------------У԰����ϵͳ---------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *-------------------���س�������---------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    *----------------------------------------------------*\n";
	cout<<"\t\t\t\t\t    ******************************************************\n";
	getchar();
		
	daohanglan();
}
int main(void)
{
	system("mode con cols=150 lines=200");		//�ı����д��ڴ�С 
	cuntu();
	//getchar();getchar();
	zhujiemian();
	return 0;
}
