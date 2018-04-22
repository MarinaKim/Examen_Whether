#pragma once
struct dates
{
	int dd;
	int mm;
	int yy;
};

struct Description
{
	int dd;
	int mm;
	int yy;
	char *time;
	double T;
	double Po;
	double P;
	int U;
	int FF;
	double Tn;
	double Tx;
	double RRR;
	int sss;
};
void cleanMas(char *a);
void fillStruct(Description *Exam, char * str);
void period(dates *start, dates *end);
void temperature(int sd, int sm, int ed, int em, Description *weather);
void Po(int sd, int sm, int ed, int em, Description *weather);

void P(int sd, int sm, int ed, int em, Description *weather);
void U(int sd, int sm, int ed, int em, Description *weather);
void FF(int sd, int sm, int ed, int em, Description *weather);
void TN(int sd, int sm, int ed, int em, Description *weather);
void TX(int sd, int sm, int ed, int em, Description *weather);
void RRR(int sd, int sm, int ed, int em, Description *weather);
void SSS(int sd, int sm, int ed, int em, Description *weather);