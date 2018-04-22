#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<locale.h>
#include<stdint.h>
#include<string.h>
#include "Header.h"
using namespace std;
FILE *file;
#define countStr 792 //в файле 792 строки
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
			fgets(str, LEN, file); //считываем по строчно
			/*printf("%s", str);*/
			fillStruct((whether+i),str); // разделяем строчку
			/*printf("%2d.%2d.%4d %s %2.1lf %3.1lf %3.1lf U-%d %d %2.1lf %2.1lf %2.1lf %d\n", (whether + i)->dd, (whether + i)->mm, (whether + i)->yy,
				(whether + i)->time, (whether + i)->T, (whether + i)->Po, (whether + i)->P, (whether + i)->U, (whether + i)->FF, (whether + i)->Tn, (whether + i)->Tx,
				(whether + i)->RRR, (whether + i)->sss);*/
		}}
	else{
		perror("Error");
		system("pause");
		exit(1);}
	fclose(file);

	// Предложения пользователю
	dates *startDate = NULL;
	startDate = (dates*)malloc(sizeof(dates));
	if (startDate != 0)	{
		printf(" Введите начало периода: ");
		fscanf(stdin, "%2d.%2d.%4d", &startDate->dd, &startDate->mm, &startDate->yy);}
	else{
		printf("error\n");
		EXIT_FAILURE;}

	dates *endDate = NULL;
	endDate = (dates*)malloc(sizeof(dates));
	if (endDate != 0){
		printf(" Введите конец периода: ");
		fscanf(stdin, "%2d.%2d.%4d", &endDate->dd, &endDate->mm, &endDate->yy);}
	else{
		printf("error\n");
		EXIT_FAILURE;}

	int pr;
	printf(" Выберите параметр:\n1-T температура\n2-P0 атмосферное давление\n3-P атмосферное давлениеd\n4-U относительная влажность\n5-FF cкорость ветра\n6-Tn минимальная температура воздуха\n7- Tx, максимальная температура \n8-RRR, количество выпавших осадков\n9-sss, высота снежного покрова\n");
	fscanf(stdin, "%d", &pr);

	switch (pr)
	{
		/*a.	T, температура воздуха (градусы Цельсия) на высоте 2 метра над поверхностью земли (отображать следующие данные в виде таблицы)
		i.	Период
		ii.	Среднее значение
		iii.	Минимальное значение(дата)
		iv.	Максимальное значение(дата)
		v.	Количество наблюдений
		*/
	case 1: {
		period(startDate, endDate);
		temperature(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*b.	P0, атмосферное давление на уровне станции (миллиметры ртутного столба) (отображать следующие данные в виде таблицы)
		i.	Период
		ii.	Среднее значение
		iii.	Минимальное значение(дата)
		iv.	Максимальное значение(дата)
		v.	Количество наблюдений
		*/
	case 2: {
		period(startDate, endDate);
		Po(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);

	}break;

		/*c.	P, атмосферное давление, приведенное к среднему уровню моря (миллиметры ртутного столба) (отображать следу-ющие данные в виде таблицы)
		i.	Период
		ii.	Среднее значение
		iii.	Минимальное значение(дата)
		iv.	Максимальное значение(дата)
		v.	Количество наблюдений
		*/
	case 3: {
		period(startDate, endDate);
		P(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*d.	U, относительная влажность (%) на высоте 2 метра над по-верхностью земли (отображать следующие данные в виде таблицы)
		i.	Период
		ii.	Среднее значение
		iii.	Минимальное значение(дата)
		iv.	Количество наблюдений
		*/
	case 4: {
		period(startDate, endDate);
		U(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*e.	FF, cкорость ветра на высоте 10-12 метров над земной по-верхностью, осредненная за 10-минутный период, непо-средственно предшествовавший сроку наблюдения (метры в секунду) (отображать следующие данные в виде табли-цы)
		i.	Период
		ii.	Среднее значение
		iii.	Минимальное значение(дата)
		iv.	Количество наблюдений
		*/
	case 5: {
		period(startDate, endDate);
		FF(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*f.	Tn, минимальная температура воздуха (градусы Цельсия) за прошедший период (не более 12 часов) (отображать следующие данные в виде таблицы)
		i.	Период
		ii.	Среднее значение
		iii.	Минимальное значение(дата)
		iv.	Количество наблюдений
		*/
	case 6: {
		period(startDate, endDate);
		TN(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*g.	Tx, максимальная температура воздуха (градусы Цельсия) за прошедший период (не более 12 часов) (отображать следующие данные в виде таблицы)
		i.	Период
		ii.	Среднее значение
		iii.	Максимальное значение(дата)
		iv.	Количество наблюдений
		*/
	case 7: {
		period(startDate, endDate);
		TX(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*h.	RRR, количество выпавших осадков (миллиметры) (отоб-ражать следующие данные в виде таблицы)
		i.	Период
		ii.	Сумма осадков
		iii.	Максимальное значение(дата)
		iv.	Число дней с осадками
		v.	Количество наблюдений
		*/
	case 8: {
		period(startDate, endDate);
		RRR(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;

		/*i.	sss, высота снежного покрова (см) (отображать следую-щие данные в виде таблицы)
		i.	Период
		ii.	Среднее значение
		iii.	Максимальное значение(дата)
		iv.	Количество наблюдений
		*/
	case 9: {
		period(startDate, endDate);
		SSS(startDate->dd, startDate->mm, endDate->dd, endDate->mm, whether);
	}break;
	}}}