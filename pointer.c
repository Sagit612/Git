#include <stdio.h>
#include <string.h>
struct conNguoi
{
	conNguoi(int t, float v1, float cc)
	{
	tuoi = t;
	vong1 = v1;
	chieucao = cc;
	}
	int tuoi;
	float vong1;
	float chieucao;
};
int main(){
	conNguoi thao(20, 90, 1.65);
	conNguoi lan(22, 95, 1.7);
	conNguoi ngoc(24, 92, 1.6);
	//declare pointer
	conNguoi *boNhi= nullptr;
	boNhi = &thao;
	printf((*boNhi).tuoi);
	return 0;
}
