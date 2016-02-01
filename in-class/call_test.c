struct big 
{
	double x, y, z;
};


int fun1(int a, int b, int c, int d, int e, int f, int g, struct big h)
{
	return a+b+c+d+e+f+g+h.x+h.y+h.z;
}

void fun2()
{
	struct big b;
	b.x = 1;
	b.y = 2;
	b.z = 3;
	int result = fun1( 1, 2, 3, 4, 5, 6, 7, b );
}
