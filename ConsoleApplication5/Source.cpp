#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<locale.h>
#include<stdint.h>
#include<string.h>
#include "Header.h"
using namespace std;
FILE *file;
#define countStr 792 //� ����� 792 ������
#define LEN 60
void main()
{
	setlocale(LC_ALL, "Rus");
	
	Description *whether = NULL;
	whether = (Description*)malloc(countStr*13 * sizeof(Description));
	if (whether == 0){
		printf("error\n");
		EXIT_FAILURE;}
	else
	{
	if ((file = fopen("source.txt", "r")) != NULL) {
		char str[LEN] = { 0 };
		
		for (int i = 0; i < countStr; i++) {
			fgets(str, LEN, file); //��������� �� �������
			/*printf("%s", str);*/
			fillStruct((whether+i),str); // ��������� �������
			/*printf("%2d.%2d.%4d %s %2.1lf %3.1lf %3.1lf U-%d %d %2.1lf %2.1lf %2.1lf %d\n", (whether + i)->dd, (whether + i)->mm, (whether + i)->yy,
				(whether + i)->time, (whether + i)->T, (whether + i)->Po, (whether + i)->P, (whether + i)->U, (whether + i)->FF, (whether + i)->Tn, (whether + i)->Tx,
				(whether + i)->RRR, (whether + i)->sss);*/
		}}
	else{
		perror("Error");
		system("pause");
		exit(1);}
	fclose(file);

	// ����������� ������������
	dates *startDate = NULL;
	startDate = (dates*)malloc(sizeof(dates));
	if (startDate != 0)	{
		printf(" ������� ������ �������: ");
		fscanf(stdin, "%2d.%2d.%4d", &startDate->dd, &startDate->mm, &startDate->yy);}
	else{
		printf("error\n");
		EXIT_FAILURE;}

	dates *endDate = NULL;
	endDate = (dates*)malloc(sizeof(dates));
	if (endDate != 0){
		printf(" ������� ����� �������: ");
		fscanf(stdin, "%2d.%2d.%4d", &endDate->dd, &endDate->mm, &endDate->yy);}
	else{
		printf("error\n");
		EXIT_FAILURE;}

	int pr;
	printf(" �������� ��������:\n1-T �����������\n2-P0 ����������� ��������\n3-P ����������� ��������d\n4-U ������������� ���������\n5-FF c������� �����\n6-Tn ����������� ����������� �������\n7- Tx, ������������ ����������� \n8-RRR, ���������� �������� �������\n9-sss, ������ �������� �������\n");
	fscanf(stdin, "%d", &pr);

	switch (pr)
	{
		/*a.	T, ����������� ������� (������� �������) �� ������ 2 ����� ��� ������������ ����� (���������� ��������� ������ � ���� �������)
		i.	������
		ii.	������� ��������
		iii.	����������� ��������(����)
		iv.	������������ ��������(����)
		v.	���������� ����������
		*/
	case 1: {
		period(startDate, endDate);
		temperature(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*b.	P0, ����������� �������� �� ������ ������� (���������� �������� ������) (���������� ��������� ������ � ���� �������)
		i.	������
		ii.	������� ��������
		iii.	����������� ��������(����)
		iv.	������������ ��������(����)
		v.	���������� ����������
		*/
	case 2: {
		period(startDate, endDate);
		Po(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);

	}break;

		/*c.	P, ����������� ��������, ����������� � �������� ������ ���� (���������� �������� ������) (���������� �����-���� ������ � ���� �������)
		i.	������
		ii.	������� ��������
		iii.	����������� ��������(����)
		iv.	������������ ��������(����)
		v.	���������� ����������
		*/
	case 3: {
		period(startDate, endDate);
		P(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*d.	U, ������������� ��������� (%) �� ������ 2 ����� ��� ��-���������� ����� (���������� ��������� ������ � ���� �������)
		i.	������
		ii.	������� ��������
		iii.	����������� ��������(����)
		iv.	���������� ����������
		*/
	case 4: {
		period(startDate, endDate);
		U(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*e.	FF, c������� ����� �� ������ 10-12 ������ ��� ������ ��-����������, ����������� �� 10-�������� ������, ����-����������� ���������������� ����� ���������� (����� � �������) (���������� ��������� ������ � ���� �����-��)
		i.	������
		ii.	������� ��������
		iii.	����������� ��������(����)
		iv.	���������� ����������
		*/
	case 5: {
		period(startDate, endDate);
		FF(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*f.	Tn, ����������� ����������� ������� (������� �������) �� ��������� ������ (�� ����� 12 �����) (���������� ��������� ������ � ���� �������)
		i.	������
		ii.	������� ��������
		iii.	����������� ��������(����)
		iv.	���������� ����������
		*/
	case 6: {
		period(startDate, endDate);
		TN(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*g.	Tx, ������������ ����������� ������� (������� �������) �� ��������� ������ (�� ����� 12 �����) (���������� ��������� ������ � ���� �������)
		i.	������
		ii.	������� ��������
		iii.	������������ ��������(����)
		iv.	���������� ����������
		*/
	case 7: {
		period(startDate, endDate);
		TX(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*h.	RRR, ���������� �������� ������� (����������) (����-������ ��������� ������ � ���� �������)
		i.	������
		ii.	����� �������
		iii.	������������ ��������(����)
		iv.	����� ���� � ��������
		v.	���������� ����������
		*/
	case 8: {
		period(startDate, endDate);
		RRR(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*i.	sss, ������ �������� ������� (��) (���������� ������-��� ������ � ���� �������)
		i.	������
		ii.	������� ��������
		iii.	������������ ��������(����)
		iv.	���������� ����������
		*/
	case 9: {
		period(startDate, endDate);
		SSS(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;
	}}}