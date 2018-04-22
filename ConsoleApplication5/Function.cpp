#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<locale.h>
#include<stdint.h>
#include<string.h>
#include"Header.h"
using namespace std;
#define LEN 60
#define countStr 792
FILE *fp = NULL;
void cleanMas(char *a)
{
	for (int i = 0; i < strlen(a); i++)
	{
		a[i] = ' ';
	}
}

void fillStruct(Description *Exam, char * str)
{
	int temp;
	float tempF;
	char m[10] = { 0 };
	int j = 0;
	/*Description *Exam = NULL;*/
	/*Exam = (Description*)malloc(sizeof(Description));*/
	if (Exam != 0)
	{//dd
		
			for (int i = 0; i < 2; i++) {
				if (str[i] != '.') {
					m[j] = str[i];
					j++;
				}
				else { break; }
			}
			/*printf("%s", m);*/
			temp = atoi(m);
			Exam->dd = temp;
			/*printf("%d\n", Exam->date->dd);*/
			/*cleanMas(m);*/

			//mm
			temp = 0;
			j = 0;
			for (int i = 3; i < 6; i++) {
				if (str[i] != '.') {
					m[j] = str[i];
					j++;
				}
				else { break; }
			}
			temp = atoi(m);
			Exam->mm = temp;
			/*cleanMas(m);*/

			//yy

			temp = 0;
			j = 0;
			for (int i = 6; i < 11; i++) {
				if (str[i] != ' ') {
					m[j] = str[i];
					j++;
				}
				else { break; }
			}
			temp = atoi(m);
			Exam->yy = temp;
			/*cleanMas(m);*/

			//time

			temp = 0;
			j = 0;
			for (int i = 11; i < 17; i++) {
				if (str[i] != ';') {
					m[j] = str[i];
					j++;
				}
				else { break; }
			}

			Exam->time = 0;
			/*cleanMas(m);*/

			//T
			char k[10] = { 0 };
			temp = 0;
			j = 0;
			for (int i = 17; i < 22; i++) {
				if (str[i] != ';') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			tempF = atof(k);
			Exam->T = tempF;
			cleanMas(k);

			//Po
			temp = 0;
			j = 0;
			for (int i = 22; i < 28; i++) {
				if (str[i] != ';') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			tempF = atof(k);
			Exam->Po = tempF;
			cleanMas(k);

			//P
			temp = 0;
			j = 0;
			for (int i = 28; i < 34; i++) {
				if (str[i] != ';') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			tempF = atof(k);
			Exam->P = tempF;
			cleanMas(k);

			//U int
			/*char l[10] = { 0 };*/
			temp = 0;
			j = 0;
			for (int i = 34; i < 37; i++) {
				if (str[i] != ';') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			temp = atoi(k);
			Exam->U = temp;
			cleanMas(k);

			//FF int
			temp = 0;
			j = 0;
			for (int i = 37; i < 39; i++) {
				if (str[i] != ';') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			temp = atoi(k);
			Exam->FF = temp;
			cleanMas(k);

			//Tn db
			temp = 0;
			j = 0;
			for (int i = 39; i < 43; i++) {
				if (str[i] != ';') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			tempF = atof(k);
			Exam->Tn = tempF;
			cleanMas(k);

			//Tx db
			temp = 0;
			j = 0;
			for (int i = 43; i < 48; i++) {
				if (str[i] != ';') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			tempF = atof(k);
			Exam->Tx = tempF;
			cleanMas(k);

			//RRR db
			temp = 0;
			j = 0;
			for (int i = 48; i < 50; i++) {
				if (str[i] != ';') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			tempF = atof(k);
			Exam->RRR = tempF;
			cleanMas(k);

			//sss int
			temp = 0;
			j = 0;
			for (int i = 50; i < 53; i++) {
				if (str[i] != ';' &&str[i] != '\0') {
					k[j] = str[i];
					j++;
				}
				else { break; }
			}
			temp = atoi(k);
			Exam->sss = temp;
			cleanMas(k);
		}
		/*printf("%2d.%2d.%4d %s %2.1lf %3.1lf %3.1lf %d %d %2.1lf %2.1lf %2.1lf %d\n", Exam->dd, Exam->mm, Exam->yy, Exam->time, Exam->T, Exam->Po,
			Exam->P, Exam->U, Exam->FF, Exam->Tn, Exam->Tx, Exam->RRR, Exam->sss);*/
}

void period(dates *startDate, dates *endDate)
{
	printf("������: %2d.%2d.%4d - %2d.%2d.%4d\n", startDate->dd, startDate->mm, startDate->yy, endDate->dd, endDate->mm, endDate->yy);
}

/*a.	T, ����������� ������� (������� �������) �� ������ 2 ����� ��� ������������ ����� (���������� ��������� ������ � ���� �������)
i.	������
ii.	������� ��������
iii.	����������� ��������(����)
iv.	������������ ��������(����)
v.	���������� ����������
*/
void temperature(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, min = 20.0, max = -20.0;
	int iMin, iMax;
	int count = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if ((weather + i)->dd == ed && (weather + i)->mm == em)
		{
			for (j = i; j < 792; j++){
				sum += (weather + j)->T;
				count++;

				if ((weather + j)->T < min)	{
					min = (weather + j)->T;
					iMin = j;}
				if ((weather + j)->T > max){
					max = (weather + j)->T;
					iMax = j;}

				if (((weather + j)->dd) == sd && (weather + j)->mm == sm){break;}}
			i = j;
		}}
	
	printf("������� ��������: %2.1lf \n", sum / count);	
	printf("���-�� ����������: %d \n", count);	
	printf("����������� ��������: %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);	
	printf("������������ ��������: %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);

	printf("--------------------------------------------------------------------------------------------\n");

	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp, "������� �������� | %2.1lf \n", sum / count);
			fprintf(fp, "���-�� ���������� | %d \n", count);
			fprintf(fp, "����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
			fprintf(fp, "������������ �������� | %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
		}
	}
}

/*b.	P0, ����������� �������� �� ������ ������� (���������� �������� ������) (���������� ��������� ������ � ���� �������)
i.	������
ii.	������� ��������
iii.	����������� ��������(����)
iv.	������������ ��������(����)
v.	���������� ����������
*/
void Po(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, min = 720.0, max = 620.0;
	int iMin, iMax;
	int count = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if ((weather + i)->dd == ed && (weather + i)->mm == em){
			for (j = i; j < 792; j++){
				sum += (weather + j)->Po;
				count++;

				if ((weather + j)->Po < min){
					min = (weather + j)->Po;
					iMin = j;}
				if ((weather + j)->Po > max){
					max = (weather + j)->Po;
					iMax = j;}

				if (((weather + j)->dd) == sd && (weather + j)->mm == sm){break;}}
			i = j;
		}}
	printf("������� �������� | %2.1lf \n", sum / count);
	printf("���-�� ���������� | %d \n", count);
	printf("����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
	printf("������������ �������� | %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);

	printf("--------------------------------------------------------------------------------------------\n");

	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp, "������� �������� | %2.1lf \n", sum / count);
			fprintf(fp, "���-�� ���������� | %d \n", count);
			fprintf(fp, "����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
			fprintf(fp, "������������ �������� | %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
		}
	}
	}

/*c.	P, ����������� ��������, ����������� � �������� ������ ���� (���������� �������� ������) (���������� �����-���� ������ � ���� �������)
i.	������
ii.	������� ��������
iii.	����������� ��������(����)
iv.	������������ ��������(����)
v.	���������� ����������
*/
void P(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, min = 820.0, max = 720.0;
	int iMin, iMax;
	int count = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if ((weather + i)->dd == ed && (weather + i)->mm == em)
		{
			for (j = i; j < 792; j++){
				sum += (weather + j)->P;
				count++;

				if ((weather + j)->P < min){
					min = (weather + j)->P;
					iMin = j;}
				if ((weather + j)->P > max)	{
					max = (weather + j)->P;
					iMax = j;}

				if (((weather + j)->dd) == sd && (weather + j)->mm == sm) { break; }}
			i = j;
		}}
	printf("������� �������� | %2.1lf \n", sum / count);
	printf("���-�� ���������� | %d \n", count);
	printf("����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
	printf("������������ �������� | %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);

	printf("--------------------------------------------------------------------------------------------\n");

	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp,"������� �������� | %2.1lf \n", sum / count);
			fprintf(fp,"���-�� ���������� | %d \n", count);
			fprintf(fp, "����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
			fprintf(fp, "������������ �������� | %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
		}
	}
}

/*d.	U, ������������� ��������� (%) �� ������ 2 ����� ��� ��-���������� ����� (���������� ��������� ������ � ���� �������)
i.	������
ii.	������� ��������
iii.	����������� ��������(����)
iv.	���������� ����������
*/
void U(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, min = 100.0;
	int iMin;
	int count = 0;
	int j = 0;
	for (int i = 0; i < 792; i++){
		if ((weather + i)->dd == ed && (weather + i)->mm == em){
			for (j = i; j < 792; j++){
				sum += (weather + j)->U;
				count++;

				if ((weather + j)->U < min){
					min = (weather + j)->U;
					iMin = j;}
				
				if (((weather + j)->dd) == sd && (weather + j)->mm == sm) { break; }
			}
			i = j;
		}}
	printf("C������ �������� | %2.1lf \n", sum / count);
	printf("���-�� ���������� | %d \n", count);
	printf("����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);

	printf("--------------------------------------------------------------------------------------------\n");

	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp, "������� �������� | %2.1lf \n", sum / count);
			fprintf(fp, "���-�� ���������� | %d \n", count);
			fprintf(fp, "����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
		}
	}
}

/*e.	FF, c������� ����� �� ������ 10-12 ������ ��� ������ ��-����������, ����������� �� 10-�������� ������, ����-����������� ���������������� ����� ���������� (����� � �������) (���������� ��������� ������ � ���� �����-��)
i.	������
ii.	������� ��������
iii.	����������� ��������(����)
iv.	���������� ����������
*/
void FF(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, min = 2.0;
	int iMin;
	int count = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if ((weather + i)->dd == ed && (weather + i)->mm == em)
		{
			for (j = i; j < 792; j++){
				sum += (weather + j)->FF;
				count++;

				if ((weather + j)->FF < min){
					min = (weather + j)->FF;
					iMin = j;}
			
				if (((weather + j)->dd) == sd && (weather + j)->mm == sm) { break; }
			}
			i = j;
		}}
	printf("������� �������� | %2.1lf \n", sum / count);
	printf("���-�� ���������� | %d \n", count);
	printf("����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);	

	printf("--------------------------------------------------------------------------------------------\n");
	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp, "������� �������� | %2.1lf \n", sum / count);
			fprintf(fp, "���-�� ���������� | %d \n", count);
			fprintf(fp, "����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
		}
	}
}

/*f.	Tn, ����������� ����������� ������� (������� �������) �� ��������� ������ (�� ����� 12 �����) (���������� ��������� ������ � ���� �������)
i.	������
ii.	������� ��������
iii.	����������� ��������(����)
iv.	���������� ����������
*/
void TN(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, min = 2.0;
	int iMin;
	int count = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if ((weather + i)->dd == ed && (weather + i)->mm == em)
		{
			for (j = i; j < 792; j++){
				sum += (weather + j)->Tn;
				count++;

				if ((weather + j)->Tn < min){
					min = (weather + j)->Tn;
					iMin = j;}

				if (((weather + j)->dd) == sd && (weather + j)->mm == sm) { break; }
			}
			i = j;
		}}
	printf("������� �������� | %2.1lf \n", sum / count);
	printf("���-�� ���������� | %d \n", count);
	printf("����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
	
	printf("--------------------------------------------------------------------------------------------\n");

	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp, "������� �������� | %2.1lf \n", sum / count);
			fprintf(fp, "���-�� ���������� | %d \n", count);
			fprintf(fp,"����������� �������� | %2.1lf - %d.%d.2018 \n", min, (weather + iMin)->dd, (weather + iMin)->mm);
		}
	}
}

/*g.	Tx, ������������ ����������� ������� (������� �������) �� ��������� ������ (�� ����� 12 �����) (���������� ��������� ������ � ���� �������)
i.	������
ii.	������� ��������
iii.	������������ ��������(����)
iv.	���������� ����������
*/
void TX(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, min = 2.0, max = 0.0;
	int iMax;
	int count = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if ((weather + i)->dd == ed && (weather + i)->mm == em){
			for (j = i; j < 792; j++){
				sum += (weather + j)->Tx;
				count++;

				if ((weather + j)->P > max)	{
					max = (weather + j)->P;
					iMax = j;}

				if (((weather + j)->dd) == sd && (weather + j)->mm == sm) { break; }
			}
			i = j;
		}}
	printf("������� �������� | %2.1lf \n", sum / count);
	printf("���-�� ���������� | %d \n", count);
	printf("������������ �������� | %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
	printf("--------------------------------------------------------------------------------------------\n");

	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp,"������� �������� | %2.1lf \n", sum / count);
			fprintf(fp,"���-�� ���������� | %d \n", count);
			fprintf(fp,"������������ �������� | %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
		}
	}
}

/*h.	RRR, ���������� �������� ������� (����������) (����-������ ��������� ������ � ���� �������)
i.	������
ii.	����� �������
iii.	������������ ��������(����)
iv.	����� ���� � ��������
v.	���������� ����������
*/
void RRR(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, max = 0.0;
	int iMax;
	int count = 0, count1=0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if ((weather + i)->dd == ed && (weather + i)->mm == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += (weather + j)->RRR;
				count++;

				if ((weather + j)->RRR > 0)
					count1++;

				if ((weather + j)->RRR > max)
				{
					max = (weather + j)->RRR;
					iMax = j;
				}

				if (((weather + j)->dd) == sd && (weather + j)->mm == sm) { break; }
			}
			i = j;
		}
	}
	printf("C���� ������� �� ������: %2.1lf \n", sum);
	printf("���-�� ���� � ��������: %d \n", count1);
	printf("���-�� ����������: %d \n", count);
	printf("������������ ��������: %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
	
	printf("--------------------------------------------------------------------------------------------\n");
	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp,"C���� ������� �� ������: %2.1lf \n", sum);
			fprintf(fp, "���-�� ���� � ��������: %d \n", count1);
			fprintf(fp, "���-�� ����������: %d \n", count);
			fprintf(fp, "������������ ��������: %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
		}
	}
}

/*i.	sss, ������ �������� ������� (��) (���������� ������-��� ������ � ���� �������)
i.	������
ii.	������� ��������
iii.	������������ ��������(����)
iv.	���������� ����������
*/
void SSS(int sd, int sm, int ed, int em, Description *weather)
{
	double sum = 0, max = -10.0;
	int iMax;
	int count = 0, count1 = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if ((weather + i)->dd == ed && (weather + i)->mm == em){
			for (j = i; j < 792; j++){
				sum += (weather + j)->sss;
				count++;

				if ((weather + j)->sss > max){
					max = (weather + j)->sss;
					iMax = j;}

				if (((weather + j)->dd) == sd && (weather + j)->mm == sm) { break; }
			}
			i = j;
		}}
	printf("������� ��������: %2.1lf \n", sum/count);
	printf("���-�� ����������: %d \n", count);
	printf("������������ ��������: %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
	
	printf("--------------------------------------------------------------------------------------------\n");

	int l;
	printf("������ �� �������� � ����? 1/0: ");
	scanf("%d", &l);

	if (l == 0)
	{
		printf(" ���� �� �������.");
	}
	else if (l == 1) {
		if ((fp = fopen("write.txt", "w")) == NULL)
		{
			printf("���� �� ������\n");
			exit(1); // ��� EXIT_FAILURE
		}
		else // ���� ������ �������
		{
			printf("Create \n");
			fprintf(fp, "������� ��������: %2.1lf \n", sum / count);
			fprintf(fp, "���-�� ����������: %d \n", count);
			fprintf(fp, "������������ ��������: %2.1lf - %d.%d.2018 \n", max, (weather + iMax)->dd, (weather + iMax)->mm);
		}
	}
}