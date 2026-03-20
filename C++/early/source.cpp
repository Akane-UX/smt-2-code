#include "header.h"

int luasPP(persegipanjang pp)
{
	return pp.panjang*pp.lebar;
}
int kelilingPP(persegipanjang pp)
{
	return 2*(pp.panjang+pp.lebar);
}