#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

#define PI 3.141592
//#define Coef //коэффициент(км/с)
const double G = 6.67 * pow(10, -11);

typedef struct Planet
{
	double mass;
	double radius;
	double speed;
	double angularVel; //угловая скорость

};

void GetInfo(struct Planet& planet) { //вносим данные про планеты
	double mass1, speed1, radius1;

	printf_s("Enter mass in kilos  ");
	scanf_s("%f", &mass1);
	printf_s("\n");

	printf_s("Enter speed in kilometers per hour ");
	scanf_s("%f", &speed1);
	printf_s("\n");

	printf_s("Enter radius in kilometrs ");
	scanf_s("%f", &radius1);
	printf_s("\n");

	planet.mass = mass1;
	planet.radius = radius1;
	planet.speed = speed1;
	planet.angularVel = (speed1 / radius1);



}

double funcYear(struct Planet planet) //считает продолжительность года
{
	return 2 * PI / planet.angularVel;

}


double GetXcoord(struct Planet planet, double time) //координата X
{
	return cos(planet.angularVel * time);
}

double GetYcoord(struct Planet planet, double time) //координата Y
{
	return sin(planet.angularVel * time);
}

double GetDistance(struct Planet planet1, struct Planet planet2, double time) // расстояние м-ду планетами
{
	double x = GetXcoord(planet1, time) - GetXcoord(planet2, time);
	double y = GetYcoord(planet1, time) - GetYcoord(planet2, time);

	return sqrt(x * x + y * y);
}


double GravInterForce(struct Planet planet1, struct Planet planet2, double time) // рассчитываем силу гравитационного взаимодействия
{
	return (G * planet1.mass * planet2.mass) / pow(GetDistance(planet1, planet2, time), 2);
}

enum Choice
{
	Set1Planet,
	Set2Planet,
	Set3Planet,
	GetYear,
	GetDist,
	GetForce,
	NoChoice
};

double GetTime()
{
	double time;
	printf_s("Set time: ");
	scanf_s("%f", &time);
	return time;
}

void menu() {
	printf_s("press\n1.To Get Info about E2G_1 \n2.To Get Info about E2G_2\n3.To Get Info about E2G_3\n4.To get info about 1 year\n5.To get info about distance\n6.To get info about Gravitational interaction force");
}

void menu1() {
	printf_s("press\n1.To Get Info about year E2G_1\n2.To Get Info about year E2G_2\n3.To Get Info about year E2G_3");
}
void main()
{
	Planet E2G_1, E2G_2, E2G_3;
	char key = '\t';
	while (key != 27) {
		system("cls");
		menu();
		key = _getch();
		Choice choise;
		switch (key) {
		case '1':
		{	system("cls");
		GetInfo(E2G_1);
		break;
		}
		case '2':
		{	system("cls");
		GetInfo(E2G_2);

		break;
		}
		case '3':
		{	system("cls");
		GetInfo(E2G_3);

		break;
		}
		case '4':
		{

			char ChoicePlanet = '\t';
		Plan_A:

			ChoicePlanet = _getch();
			double year;
			system("cls");
			menu1();

			switch (ChoicePlanet) {
			case '1': {
				system("cls");
				year = funcYear(E2G_1);
				printf_s("1 year equals: %f", year);
				break;
			}
			case '2': {
				system("cls");
				year = funcYear(E2G_2);
				printf_s("1 year equals: %f", year);
				break;
			}
			case '3': {
				system("cls");
				year = funcYear(E2G_3);
				printf_s("1 year equals: %f", year);
				break;
			}
			default: {
				goto Plan_A;
			}
			}
			while (!_kbhit())
			{
			}
			break;

		}
		case '5':
		{		system("cls");
		double time = GetTime();
		char ChoicePlanet = '\t';
	Plan:
		ChoicePlanet = _getch();
		switch (ChoicePlanet) {
		case '1': {
			double Distance = GetDistance(E2G_1, E2G_2, time);
			printf_s("Distance between E2G_1 and E2G_2 in time: %f  equals: %f", time, Distance);
			break;
		}
		case '2': {
			double Distance = GetDistance(E2G_1, E2G_3, time);
			printf_s("Distance between E2G_1 and E2G_3 in time: %f  equals: %f", time, Distance);
			break;
		}
		case '3': {
			double Distance = GetDistance(E2G_2, E2G_3, time);
			printf_s("Distance between E2G_2 and E2G_3 in time: %f  equals: %f", time, Distance);
			break;
		}
		default: {
			goto Plan;
		}
		}
		break;
		}
		case '6':
		{	system("cls");
		double time = GetTime();
		char ChoicePlanet = '\t';
	Plan_B:
		ChoicePlanet = _getch();
		switch (ChoicePlanet) {
		case '1': {
			double Distance = GravInterForce(E2G_1, E2G_2, time);
			printf_s("Gravitational interaction force between E2G_1 and E2G_2 in time: %f  equals: %f", time, Distance);
			break;
		}
		case '2': {
			double Distance = GravInterForce(E2G_1, E2G_3, time);
			printf_s("Gravitational interaction force between E2G_1 and E2G_3 in time: %f  equals: %f", time, Distance);
			break;
		}
		case '3': {
			double Distance = GravInterForce(E2G_2, E2G_3, time);
			printf_s("Gravitational interaction force between E2G_2 and E2G_3 in time: %f  equals: %f", time, Distance);
			break;
		}
		default: {
			goto Plan_B;
		}
		}
		break;
		break;
		}

		}

	}

}